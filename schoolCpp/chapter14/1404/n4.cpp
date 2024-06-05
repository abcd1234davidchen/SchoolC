#include<iostream>

using namespace std;

class universityStaff{
    private:
        string name;
    public:
        universityStaff(string n){
            name = n;
        }
        universityStaff(){
            name = "";
        }
        universityStaff(const universityStaff &us){
            name = us.name;
        }
        string getName(){
            return name;
        }
        universityStaff& operator= (const universityStaff &us){
            if(this!=&us) name = us.name;
            return *this;
        }
        friend istream& operator>>(istream &in, universityStaff &us){
            in>>us.name;
            return in;
        }
        friend ostream& operator<<(ostream &out, universityStaff &us){
            out<<us.name;
            return out;
        }
};
class student{
    private:
        string name;
        int registrationNumber;
        universityStaff proctor;
    public:
        student(string n, int r, universityStaff p){
            name = n;
            registrationNumber = r;
            proctor = p;
        }
        student(){
            name = "";
            registrationNumber = 0;
            proctor = universityStaff();
        }
        student(const student &s){
            name = s.name;
            registrationNumber = s.registrationNumber;
            proctor = s.proctor;
        }
        string getName(){
            return name;
        }
        int getRegistrationNumber(){
            return registrationNumber;
        }
        universityStaff getProctor(){
            return proctor;
        }
        student& operator= (const student &s){
            name = s.name;
            registrationNumber = s.registrationNumber;
            proctor = s.proctor;
            return *this;
        }
        friend istream& operator>>(istream &in, student &s){
            in>>s.name>>s.registrationNumber>>s.proctor;
            return in;
        }
        friend ostream& operator<<(ostream &out, student &s){
            out<<s.name<<" "<<s.registrationNumber<<" "<<s.proctor;
            return out;
        }
};
class scienceStudent: public student{
    private:
        string scienceDiscipline;
        string graduateCourse;
    public:
        scienceStudent(string n, int r, universityStaff p, string sd, string gc): student(n, r, p){
            scienceDiscipline = sd;
            graduateCourse = gc;
        }
        scienceStudent(student s, string sd, string gc): student(s){
            scienceDiscipline = sd;
            graduateCourse = gc;
        }
        scienceStudent(){
            scienceDiscipline = "";
            graduateCourse = "";
        }
        scienceStudent(const scienceStudent &ss):student(ss){
            scienceDiscipline = ss.scienceDiscipline;
            graduateCourse = ss.graduateCourse;
        }
        string getScienceDiscipline(){
            return scienceDiscipline;
        }
        string getGraduateCourse(){
            return graduateCourse;
        }
        scienceStudent& operator= (const scienceStudent &ss){
            student::operator=(ss);
            scienceDiscipline = ss.scienceDiscipline;
            graduateCourse = ss.graduateCourse;
            return *this;
        }
        friend istream& operator>>(istream &in, scienceStudent &ss){
            in>>ss.scienceDiscipline>>ss.graduateCourse;
            return in;
        }
        friend ostream& operator<<(ostream &out, scienceStudent &ss){
            out<<ss.getName()<<" "<<ss.getRegistrationNumber()<<" "<<ss.getProctor().getName()<<" "<<ss.scienceDiscipline<<" "<<ss.graduateCourse;
            return out;
        }
};

int main(){
    universityStaff us("Dr. John");
    student s("John Doe", 1234, us);
    scienceStudent ss2(s, "Physics", "MSc");
    scienceStudent ss("Jane Doe", 5678, us, "Physics", "MSc");
    ss2=ss;
    //cout<<ss.getName();
    cout<<ss2;
}
