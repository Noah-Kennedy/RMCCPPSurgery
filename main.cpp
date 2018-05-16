#include <iostream>
#include <string>
#include <cstring>

using namespace std;

bool killed = false;

string read_next_command();

void handle_drv(float, float);

void handle_mt(float);

void handle_intk(float);

void handle_dmp(float);

void handle_kill() {
    killed = !killed;
}

void test(int, const string &);

void handle_command(const string &message) {
    string command;

    command = strtok(const_cast<char *>(message.c_str()), " ");

    if (command == "drv") {

        string left, right;
        float left_speed, right_speed;

        left = strtok(nullptr, " ");
        right = strtok(nullptr, " ");

        left_speed = static_cast<float>(atof(left.c_str()));
        right_speed = static_cast<float>(atof(right.c_str()));

        if (!killed)
            handle_drv(left_speed, right_speed);

    } else if (command == "mt") {

        string speed_str;
        float speed;

        speed_str = strtok(nullptr, " ");
        speed = static_cast<float>(atof(speed_str.c_str()));

        if (!killed)
            handle_mt(speed);

    } else if ("intk") {

        string speed_str;
        float speed;

        speed_str = strtok(nullptr, " ");
        speed = static_cast<float>(atof(speed_str.c_str()));

        if (!killed)
            handle_intk(speed);

    } else if (command == "dmp") {

        string speed_str;
        float speed;

        speed_str = strtok(nullptr, " ");
        speed = static_cast<float>(atof(speed_str.c_str()));

        if (!killed)
            handle_dmp(speed);

    } else if (command == "kill") {

        handle_kill();

    }

}

void setup() {

}

void loop() {

    string command;

    command = read_next_command();

    if (command != nullptr) {
        handle_command(command);
    }

}

int main() {
    setup();

    while (true) {
        loop();
    }
}

void test(int test_result, const string &description) {
    if (!test_result) {
        cout << "FAILED: " << description << endl;
    }
}