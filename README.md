# IPv4 Chat

This is a chat for Debian using udp datagrams and ipv4. It uses 2 threads -
one for server and another for client (actually 3, there is also a main thread).

By now it is not fully working cause I am not really familiar with
socket programming in cpp, but the idea is there.

## Build & Run

To build, run `$ sh build.sh`

You will find executables in `./build` directory.
Run `$ ./build/messenger <ip> <port>` to start the app.

Run `$ make build` if you want only the executables to be built.

## Test & Clean

Tests are run by default when you run `$ make`,
but you can also run them with `$ make run-tests`.

To clean the project run `$ make clean`.
