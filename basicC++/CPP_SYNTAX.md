# C++ 語法整理：Lab01–Lab08

涵蓋基本輸出、變數、輸入輸出、數學運算、條件判斷、迴圈、函式與陣列。範例以 C++17 為準，每段可獨立閱讀。

## 1. 程式基本結構與輸出

```cpp
#include <iostream> // 提供 cin、cout、endl
using namespace std;

int main()
{
    cout << "Hello, C++!" << '\n';
    return 0;
}
```

- `#include`：引入標頭檔，取得需要的功能。
- `main()`：程式開始執行的位置。
- `{ }`：界定程式區塊。
- `;`：結束一個敘述。
- `//`：單行註解；`/* ... */`：多行註解。
- `std::cout`：標準輸出；`<<` 將內容送到輸出。
- `using namespace std;`：讓你省略 `std::`，例如寫成 `cout`。
- `return 0;`：表示程式正常結束。

```cpp
cout << "Name: " << "Amy" << '\n';
cout << "第一行\n第二行\n";
cout << "引號：\"，反斜線：\\\n";
```

`'\n'` 與 `endl` 都能換行；`endl` 還會立即送出輸出緩衝區的內容，一般換行用 `'\n'` 即可。字元用單引號，例如 `'A'`；字串用雙引號，例如 `"Amy"`。

## 2. 變數、常數與型別轉換

| 型別 | 用途 | 宣告範例 |
|---|---|---|
| `int` | 整數 | `int score = 90;` |
| `double` | 浮點數，可表示小數 | `double gpa = 4.25;` |
| `char` | 單一字元 | `char grade = 'A';` |
| `bool` | 布林值：真或假 | `bool passed = true;` |
| `string` | 字串，需 `<string>` | `string name = "Amy Chen";` |

```cpp
int a = 4, b = 7;
const double PI = 3.14159;
double average = (80 + 90 + 70) / 3.0;
double ratio = static_cast<double>(a) / b;
```

### 整數除法

```cpp
cout << 5 / 2;                         // 2：兩邊都是 int
cout << 5 / 2.0;                       // 2.5：先以浮點數運算
cout << static_cast<double>(5 / 2);    // 2.0：除完才轉型，已經失去小數
```

`static_cast<型別>(值)` 是明確指定的型別轉換。計算平均、比例、勝率時，要在除法發生前轉成浮點數。

### const 與 #define

```cpp
const double PI = 3.14159; // 有型別的常數，通常優先使用
#define OFFSET 3 + 0.14    // 前置處理器直接替換文字
```

`OFFSET * 2` 會被替換成 `3 + 0.14 * 2`。若使用巨集運算式，應加括號，例如 `#define OFFSET (3 + 0.14)`；初學時優先使用 `const` 比較清楚。

## 3. 輸入、讀檔與輸出排版

### cin 與 getline：讀取一個值，還是讀取一整行？

`cin` 是標準輸入串流，可以把它想成「等待程式讀取的一串字元」。輸入 `21` 再按 Enter，輸入中就包含 `2`、`1` 與換行字元 `\n`。不同讀取方式，取走的字元不同。

| 寫法 | 讀取方式 | 空白與換行如何處理 |
|---|---|---|
| `cin >> number` | 依變數型別解析一個值 | 預設略過開頭空白；數字後的換行通常留下 |
| `cin >> word` | 讀取一個字串單字 | 預設略過開頭空白，遇到空白或換行停止；分隔字元留下 |
| `cin >> ch` | 讀取一個字元 | 預設略過空白、Tab 與換行 |
| `getline(cin, line)` | 讀取一整行到 `string` | 保留行內與行首空白；取走換行，但不把換行存入字串 |
| `cin.get(ch)` | 讀取下一個字元 | 不略過空白，因此也能讀到空格或換行 |

#### 例子 1：姓名中有空白

```cpp
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name;
    getline(cin, name);
    cout << "Hello, " << name << "!\n";
}
```

輸入：

```text
Amy Chen
```

輸出：

```text
Hello, Amy Chen!
```

如果改成 `cin >> name;`，`name` 只會得到 `Amy`，剩下的 ` Chen\n` 仍在輸入中。單獨使用 `getline()` 時，也不需要先加 `ignore()`。

#### 例子 2：先讀年級，再讀完整姓名

常見問題出在 **先使用 `>>`，接著使用 `getline()`**。

輸入：

```text
2
Amy Chen
```

若這樣寫：

```cpp
cin >> year;
getline(cin, name);
```

發生的事：

1. `cin >> year` 讀走 `2`，留下 `\nAmy Chen\n`。
2. `getline()` 馬上遇到第一個 `\n`，讀到空字串並取走該換行。
3. `Amy Chen` 尚未被讀取，看起來就像姓名輸入被跳過。

以下是可直接執行的完整寫法：

```cpp
#include <iostream>
#include <limits>
#include <string>
using namespace std;

int main()
{
    int year;
    string name;

    cout << "Enter year: ";
    cin >> year;

    // 丟棄這一行剩下的字元，包含最後的換行。
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter full name: ";
    getline(cin, name);

    cout << "Year: " << year << '\n';
    cout << "Name: " << name << '\n';
}
```

搭配前面的輸入，最後兩行輸出為：

```text
Year: 2
Name: Amy Chen
```

`numeric_limits<streamsize>::max()` 提供很大的丟棄上限；搭配 `'\n'`，表示一路丟棄到本行結束。這個範例假設年級輸入有效；輸入失敗的處理見下方。

**注意：這個方法適用於「數字與姓名分別在不同行」。** 如果輸入是 `2 Amy Chen`，它會連姓名一起丟棄，不能直接套用。

#### ignore()、ws、clear() 與 get() 有什麼不同？

| 工具 | 功能 | 使用時機與注意事項 |
|---|---|---|
| `cin.ignore()` | 預設丟棄一個字元 | 只有確定下一個字元就是換行時，才足以清掉換行 |
| `cin.ignore(n, '\n')` | 最多丟棄 n 個字元，或直到取走換行 | 用來捨棄本行剩餘內容 |
| `cin >> ws` | 持續取走開頭所有空白字元 | 包含空格、Tab、換行；會略過空行與姓名前的空白 |
| `cin.clear()` | 重設串流錯誤狀態 | 輸入格式錯誤後使用；不會取走任何剩餘字元 |
| `cin.get(ch)` | 取走一個字元並存入 ch | 需要讀取空白或逐字元處理時使用 |

常見的簡短寫法：

```cpp
cin >> year;
getline(cin >> ws, name);
```

`ws` 會先略過所有開頭空白，再交給 `getline()` 讀取。它適合「姓名不能是空白行，也不需要保留行首空白」的情況；若要保留空行或縮排，應使用一般 `getline()` 並在正確位置處理上一行換行。

**不要每次輸入後都呼叫 `clear()` 或 `ignore()`。** 正常的連續 `cin >> a >> b` 會自行略過空白；連續使用 `getline()` 也會自行取走每行的換行。

#### 例子 3：輸入數字失敗後重新讀取

如果 `int age; cin >> age;` 遇到 `abc`，數字解析失敗，串流會進入錯誤狀態。必須先 `clear()` 解除錯誤，再 `ignore()` 捨棄錯誤輸入，才能繼續讀取。

```cpp
#include <iostream>
#include <limits>
using namespace std;

int main()
{
    int age;
    cout << "Enter age: ";

    while (!(cin >> age))
    {
        // 輸入結束或底層讀取失敗時，結束程式，避免無限重試。
        if (cin.eof() || cin.bad())
        {
            return 1;
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter an integer: ";
    }

    cout << "Age: " << age << '\n';
}
```

輸入先給 `abc`、再給 `20`，程式會提示重試，最後輸出 `Age: 20`。

這是「整數解析失敗」的重試範例，沒有驗證整行只能包含一個整數。例如 `20abc` 仍可能先成功讀出 `20`，留下 `abc`。

#### 例子 4：讀取到輸入結束

```cpp
string line;
while (getline(cin, line))
{
    cout << '[' << line << "]\n";
}
```

每次成功讀到一行就執行一次；空白行也是有效輸入，會輸出 `[]`。到達輸入結束（EOF，End of File）且沒有更多內容可讀時，迴圈結束。不要用 `while (!cin.eof())` 代替讀取成功與否的判斷。

#### string 版 getline 與字元陣列版 getline

```cpp
string name;
getline(cin, name); // <string> 的自由函式，字串長度可自動調整

char buffer[50];
cin.getline(buffer, 50); // 最多存 49 個字元，保留一格給 '\0'
```

兩者名稱相近，接收的資料型別不同。初學讀整行時，通常優先使用 `string` 搭配 `getline(cin, name)`。字元陣列若容量不足以容納整行，還可能使串流進入錯誤狀態，需要另外處理。

### 使用 ifstream 讀取檔案

```cpp
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    ifstream file("data.txt");
    if (!file)
    {
        cerr << "Cannot open data.txt\n";
        return 1;
    }

    int a, b;
    while (file >> a >> b)
    {
        cout << a << ' ' << b << '\n';
    }
}
```

- `ifstream`：輸入檔案串流，讀法與 `cin` 類似。
- `while (file >> a >> b)`：每次成功讀到一組資料才進入迴圈。
- 不要用 `while (!file.eof())` 判斷是否還有一組完整資料。
- `data.txt` 這種相對路徑，是相對於程式執行時的工作目錄。
- 串流物件離開作用範圍時會自動關檔，也可呼叫 `file.close()`。

### iomanip 排版

```cpp
#include <iomanip>

cout << left << setw(20) << "Name"
     << right << setw(6) << "Class"
     << right << setw(10) << "Year"
     << right << setw(12) << "GPA" << '\n';

cout << fixed << setprecision(2) << 4.26789123; // 4.27
```

| 工具 | 效果 |
|---|---|
| `setw(n)` | 設定下一個輸出項目的最小欄寬；之後要重新設定 |
| `left` / `right` | 靠左／靠右對齊，設定會持續生效 |
| `fixed` | 使用固定小數格式，設定會持續生效 |
| `setprecision(n)` | 配合 `fixed` 時指定小數位數；未使用 `fixed` 時通常指定有效位數 |

`setw()` 不會截斷太長的內容。自動評分時，也要注意冒號、大小寫、空格與換行。

## 4. 運算子與數學函式

| 類別 | 語法 | 說明 |
|---|---|---|
| 算術 | `+ - * / %` | `%` 是整數取餘數，不能對 `double` 使用 |
| 指派 | `= += -= *= /=` | `a += 2` 等同 `a = a + 2` |
| 比較 | `== != < <= > >=` | 結果是 `bool` |
| 邏輯 | `&&`、`||`、`!` | 且、或、非 |
| 遞增／遞減 | `++i`、`i++`、`--i`、`i--` | 改變變數值；前置與後置回傳的值不同 |

```cpp
bool inRange = (x >= 0 && x <= 10);
bool outside = (x < 0 || x > 10);
```

不能用 `0 <= x <= 10` 表示數學上的連續不等式；要寫成兩次比較並用 `&&` 連接。判斷相等用 `==`，`=` 是指派。

### 常見數學函式

```cpp
#include <cmath>
#include <algorithm>

abs(-5);        // 5
fabs(-2.5);     // 2.5
pow(2.0, 3.0);  // 8.0
sqrt(9.0);      // 3.0
exp(1.0);       // e 的一次方
log10(100.0);   // 2.0
floor(2.5);     // 2.0
ceil(2.5);      // 3.0
round(2.5);     // 3.0
max(0.0, x);    // x 為 double 時，兩個參數型別一致
```

- `sin()`、`cos()` 使用弧度：`radians = degrees * PI / 180.0`。
- `log10(x)` 的實數輸入需大於 0；除法前也要避免分母為 0。
- `^` 是位元互斥或運算，**不是次方**；平方可寫 `x * x`。
- `floor(-2.5)` 是 `-3.0`，與轉成整數後向零截斷不同。

### rand 與 srand

```cpp
#include <cstdlib>

srand(0);                 // 固定種子，方便在同一實作下重現結果
int dice = rand() % 6 + 1; // 1～6
int card = rand() % 13 + 1;
```

課堂常用的整數範圍寫法為 `rand() % (max - min + 1) + min`。固定種子不保證不同平台得到相同序列；取餘數也可能造成機率偏差，這種寫法適合課堂練習。

## 5. 條件判斷

### if、else if、else

```cpp
if (score >= 90)
{
    cout << "A\n";
}
else if (score >= 80)
{
    cout << "B\n";
}
else
{
    cout << "C or below\n";
}
```

`if / else if / else` 只執行第一個符合的分支；多個獨立的 `if` 會各自判斷，可能執行多次。建議即使只有一個敘述也保留大括號，減少之後加程式時的錯誤。

### switch

```cpp
switch (mode)
{
case 1:
    cout << "Name\n";
    break;
case 2:
    cout << "Department\n";
    break;
default:
    cout << "Unknown mode\n";
    break;
}
```

- `switch` 適合判斷整數、字元或列舉值，不能直接判斷 `string`。
- `case` 的值必須是編譯時可確定的常數。
- `break` 離開 `switch`；省略時可能繼續執行下一個分支。
- `default` 處理沒有符合任何 `case` 的情況。

## 6. 迴圈

### for：次數明確時

```cpp
for (int i = 0; i < 5; i++)
{
    cout << i << ' '; // 0 1 2 3 4
}
```

順序為：初始化一次 → 檢查條件 → 執行內容 → 更新 → 再檢查條件。

### while：依條件重複

```cpp
int i = 0;
while (i < 5)
{
    cout << i << ' ';
    i++;
}
```

### do-while：至少執行一次

```cpp
int choice;
do
{
    cin >> choice;
} while (choice < 1 || choice > 3); // 最後需要分號
```

### 巢狀迴圈與流程控制

```cpp
for (int row = 0; row < 3; row++)
{
    for (int col = 0; col < 4; col++)
    {
        cout << row << ',' << col << ' ';
    }
    cout << '\n';
}
```

- `break`：離開最內層的迴圈或 `switch`。
- `continue`：跳過本輪剩下的內容，進入下一輪；在 `for` 中仍會先執行更新部分。
- `return`：結束整個函式。

常見錯誤包括忘記更新變數、把 `i++` 寫成 `i--`、把 `==` 寫成 `=`，以及在 `for (...)` 後多加分號。迴圈是否結束，要看條件能否在某一輪變成 `false`。

## 7. 函式、參數傳遞與遞迴

### 宣告、呼叫與定義

```cpp
#include <iostream>
using namespace std;

int add(int a, int b); // 函式宣告：讓編譯器先知道介面

int main()
{
    cout << add(3, 4) << '\n'; // 呼叫函式
}

int add(int a, int b) // 函式定義：實際內容
{
    return a + b;
}
```

`int` 表示回傳整數；`void` 表示不回傳值。若函式在呼叫位置之前已經完整定義，就不必另外寫宣告。

### 傳值與傳參考

```cpp
void changeValue(int x)
{
    x = 10; // 改的是副本，不影響呼叫端
}

void changeReference(int& x)
{
    x = 10; // x 是原變數的別名，會改到呼叫端
}
```

| 方式 | 寫法 | 效果 |
|---|---|---|
| 傳值 | `int x` | 複製一份值 |
| 傳參考 | `int& x` | 透過別名操作原變數 |
| 唯讀參考 | `const string& s` | 避免複製字串，同時禁止透過 s 修改它 |

區域變數只在所屬區塊內有效；全域變數宣告在函式外，可被多個函式存取，但會讓程式對共同狀態產生依賴。

### 遞迴

遞迴就是函式呼叫自己，必須有停止條件，並且每次呼叫都朝停止條件前進。

```cpp
int factorial(int n) // 假設 0 <= n <= 10
{
    if (n == 0)
    {
        return 1;
    }
    return n * factorial(n - 1);
}
```

若沒有停止條件，或參數一直無法到達停止條件，呼叫會不斷累積，最後可能耗盡呼叫堆疊的空間。整數也有範圍限制，不能假設所有計算結果都放得進 `int`。

## 8. 一維與二維陣列

### 一維陣列

```cpp
const int MAX_SIZE = 20;
int values[MAX_SIZE] = {}; // 全部初始化成 0
int sample[3] = {10, 20, 30};

cout << sample[0]; // 第一個元素
sample[2] = 99;    // 第三個元素
```

- 長度為 `n` 的陣列，合法索引是 `0` 到 `n - 1`。
- 存取 `values[n]` 會越界，C++ 原生陣列不會自動檢查。
- 區域陣列若沒有初始化，例如 `int a[20];`，不能直接讀取尚未賦值的元素。
- 標準 C++ 的原生陣列長度需是編譯時可確定的常數。不要依賴 `cin >> n; int a[n];` 這類編譯器擴充；可宣告固定最大容量，再使用前 `n` 個元素。

### 陣列傳入函式

```cpp
void printArray(const int values[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << values[i] << ' ';
    }
    cout << '\n';
}
```

陣列作為這種函式參數時，不會複製整個陣列，也不會自動帶入長度，因此要另外傳 `size`。若沒有 `const`，函式修改元素會影響呼叫端。

### 二維陣列

```cpp
const int ROWS = 3;
const int COLS = 4;
int grid[ROWS][COLS] = {};

grid[1][2] = 7; // 第 2 列、第 3 欄

for (int row = 0; row < ROWS; row++)
{
    for (int col = 0; col < COLS; col++)
    {
        cin >> grid[row][col];
    }
}
```

二維陣列傳入函式時，需讓編譯器知道每列有幾欄：

```cpp
void showGrid(const int grid[][COLS], int rows)
{
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            cout << grid[row][col] << ' ';
        }
        cout << '\n';
    }
}
```

### 字元陣列與字串的差別

```cpp
char board[10][10];
for (int row = 0; row < 10; row++)
{
    for (int col = 0; col < 10; col++)
    {
        cin >> board[row][col];
    }
}
```

`char board[10][10]` 的每列只有 10 個字元空間，沒有額外位置放 C 字串結尾的 `'\0'`。因此不要直接把 `board[row]` 當成以 `'\0'` 結尾的字串來輸出；逐格讀取、逐格輸出比較清楚。

## 9. 常用標頭檔速查

| 標頭檔 | 常用功能 |
|---|---|
| `<iostream>` | `cin`、`cout`、`cerr`、`endl` |
| `<string>` | `string`、字串版 `getline()` |
| `<fstream>` | `ifstream`、`ofstream` |
| `<iomanip>` | `setw()`、`setprecision()` 等輸出排版工具 |
| `<cmath>` | `sqrt()`、`pow()`、`exp()`、`log10()`、三角函式 |
| `<algorithm>` | `max()`、`min()` 等演算法工具 |
| `<cstdlib>` | `rand()`、`srand()`、整數版 `abs()` |
| `<ctime>` | `time()` |
| `<limits>` | `numeric_limits`，例如配合 `cin.ignore()` |

## 10. 交作業前快速檢查

- 每題各自存成一個 `.cpp`，同一個程式只能有一個 `main()`。
- 使用到的型別和函式有引入對應標頭檔。
- 小數除法在除之前轉型，輸出的小數位數正確。
- `=` 與 `==`、`&&` 與 `||` 沒有混用。
- 讀檔方式與題目要求一致，執行位置能找到輸入檔。
- 迴圈確實能結束，索引未超過陣列邊界。
- 輸出的大小寫、標點、空格和換行符合規格。
- 排版完成後，重新編譯並測試題目提供的範例。
