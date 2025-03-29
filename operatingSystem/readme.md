# Operating System Assignment: Client-Server Model and Threads
In this assignment,I wrote a server and several clients that connects to the server through socket. With each connection being formed, a pthread is made to handle the client.
## Manual
The section is an instruction on how to use the program.
### Server
Each output besides Init wipe terminal then write to whiteboard and output whiteboard with MUTEX on.
|Process|Output|Notes|
|---|---|---|
|Init|`input <address> <port>`|input {address} {port}|
|Init Success|`<IP: {address} Port: {port}>`||
|Connect|`<Client {name} on address: {address}/{port}>`|1. open thread 2. check if username already exist <br> 3. send `<User {name} is online, address: {address}/{port}>` to all online client <br> 4. send `<Success>` and current online user list `<User {name} is online, address: {address}/{port}>` to new connected also add new connected to list|
|Chat|`<{sender} to {recipient}> Message: {message}`|forward message from sender to recipient <br> or throws `<User {recipient} does not exist>` to sender|
|Disconnect|`<Client {name} disconnected>`|send `<User {name} disconnected>` to everyone, remove from list and close thread|

### Client
|Command|Output|Notes|
|---|---|---|
|`$ connect {address} {port}`|`<Success>` <br> `<User {name} is online, address: {address}/{port}>`|Connection formed and list out online user|
| |`<User already exist>`|User already exist||`$ chat {user} "{message}"`|blank <br> `User {user} does not exist`|Success <br> Sent to invalid user|
|`$ bye`|blank|Disconnect from server|

## Idea

By design:
 - The whiteboard is a string
 - MUTEX is present everytime whiteboard is updated
 - Besides the init message, every message in whiteboard has timestamp
 - Whiteboard is shown by wiping the whole terminal then output the whole string
 - `usleep` was used to ensure process is correctly ordered and does not stashed to one, causing difficulty in display
 - A hidden `kill` command is written to kill all existing client and the server or the client only when disconencted

The whole process of an connection:

0. The program is compiled using makefile and tested on a mac with multiple terminal windows

1. Turn on server and input the IP and Port to allow connection through socket
    - The server would notified and killed if the desired one is unusable
    - Start the whiteboard with message of IP address and Port if usable
2. Connect client to server
    - Client would hold a bool to track connection status
    - Server would maintain and listen connection through pthread
    - Server holds a vector of existing user
    - Server holds a map to map user name with socket
    - Client would be prompted to redo connection if error occurs
    - Process:
        1. The server would throw a success message first to make client know the connection is established and change connection bool
        2. Server would check if the chosen user name was taken already, preventing the situation of sending a message but arrive to a wrong user
        - If the name already exist, throw error message back, disconnect and kill pthread
        3. Throw info of new user to existing user. Throw info of existing users to new user for new user to know who to message
        - Whiteboard would be updated if connection is formed
        - User vector and map would be updated
    - If the connection prompt was made when connection is formed, the client would handle like as if it was disconnected then reconnect as new user
    - If the connection was never made, the following processes couldn't be done
3. Chat another client
     - The whiteboard is updated regardless of the existance of user
     - Process:
        1. Check if the recipient is in the server
        - Throw error back to user if the recipient is not in map
        2. Message is parsed before to support both with and without quotation mark
        3. Message is sent through send command
       
4. Disconnect
     - The client would disconnect but not stopped, allowing a new connection through connect command
     - Process:
        1. The connection bool would be changed
        2. Client would close the socket to connect to server
        3. Regardless of disconnect command or disconnection itself detected by server, the server would notify all other user that the user is offline
        4. The server would shut down the connection and stop pthread
     - Only way of stopping the client is through kill command