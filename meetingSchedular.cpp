#include <iostream>
#include <vector>
using namespace std;

class Meeting;
typedef vector<Meeting> Calender;

class Room {
private:
    string name;
    Calender calender;
public:
    Room(string name);
    bool book(int ,int); //start this function
    const string &getName() const ;
};

class Meeting {
    int start, end;
    Room room;
public:
    Meeting(int start, int end, Room room);
    int getEnd() const;
    int getStart() const;
};

class Scheduler {
    vector<Room> rooms;
public:
    Scheduler (vector<Room> rooms);
    string book(int start, int end);
};
Room :: Room(string name){
    this->name = name;
}
bool Room::book(int start, int end){
    for(Meeting m:calender){
        //To be Implemented
        if(m.getStart() < end && m.getEnd() > start) return false;
    }
    Meeting meeting(start, end, *this);
    calender.push_back(meeting);
    return true;
} 
const string &Room::getName() const { return name;}
int Meeting::getStart() const { return start;}
int Meeting::getEnd() const { return end;}


Meeting :: Meeting(int start, int end, Room room):room(room) {
    this->start = start;
    this->end = end;
}

Scheduler::Scheduler(vector<Room> rooms) {
    this->rooms = rooms;
}

string Scheduler::book(int start, int end){
    for(Room &room:rooms){
        bool flag = room.book(start, end);
        if(flag){
            return room.getName();
        }
    }
    return "No rooms available";
}

int main()
{
    Room room1("Atlas");
    Room room2("Nexus");
    Room room3("HolyCow");

    vector<Room> roomVec;
    roomVec.push_back(room1);
    roomVec.push_back(room2);
    roomVec.push_back(room3);

    Scheduler scheduler(roomVec);

    cout << scheduler.book(2, 5) << "\n"; // Atlas
    cout << scheduler.book(5, 8) << "\n"; // Atlas
    cout << scheduler.book(4, 8) << "\n"; // Nexus
    cout << scheduler.book(3, 6) << "\n"; // Holycow
    cout << scheduler.book(7, 8) << "\n"; // Holycow
    cout << scheduler.book(6, 9) << "\n"; // Atlas
    return 0;
}