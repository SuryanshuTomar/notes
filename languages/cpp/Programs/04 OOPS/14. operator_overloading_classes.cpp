#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class YoutubeChannel {
private:
    string name;
    int subscribers;

public:
    // Constructor
    YoutubeChannel(string n = "", int s = 0) : name(n), subscribers(s) {}

    // Overload + operator (merge subscribers)
    YoutubeChannel operator+(const YoutubeChannel& other) const {
        return YoutubeChannel(name + " & " + other.name, subscribers + other.subscribers);
    }

    // Overload - operator (subtract subscribers)
    YoutubeChannel operator-(int count) const {
        return YoutubeChannel(name, subscribers - count);
    }

    // Overload == operator
    bool operator==(const YoutubeChannel& other) const {
        return (name == other.name && subscribers == other.subscribers);
    }

    // Overload << operator (friend function)
    friend ostream& operator<<(ostream& os, const YoutubeChannel& ch) {
        os << ch.name << " (" << ch.subscribers << " subscribers)";
        return os;
    }

    // Overload >> operator (friend function)
    friend istream& operator>>(istream& is, YoutubeChannel& ch) {
        cout << "Enter channel name: ";
        getline(is, ch.name);
        cout << "Enter subscriber count: ";
        is >> ch.subscribers;
        return is;
    }

    // Overload prefix ++ operator
    YoutubeChannel& operator++() {
        ++subscribers;
        return *this;
    }

    // Overload postfix ++ operator
    YoutubeChannel operator++(int) {
        YoutubeChannel temp = *this;
        subscribers++;
        return temp;
    }

    friend class MyCollection; // Allow MyCollection to access private members
};

class MyCollection {
private:
    vector<YoutubeChannel> channels;

public:
    // Overload += operator to add channel
    MyCollection& operator+=(const YoutubeChannel& channel) {
        channels.push_back(channel);
        return *this;
    }

    // Overload -= operator to remove channel by name
    MyCollection& operator-=(const string& channelName) {
        channels.erase(remove_if(channels.begin(), channels.end(),
            [&channelName](const YoutubeChannel& ch) { return ch.name == channelName; }), channels.end());
        return *this;
    }

    // Overload [] operator for access
    YoutubeChannel& operator[](int index) {
        return channels[index];
    }

    // Overload << operator for output
    friend ostream& operator<<(ostream& os, const MyCollection& collection) {
        os << "My YouTube Channels:\n";
        for (const auto& channel : collection.channels) {
            os << "- " << channel << "\n";
        }
        return os;
    }

    int size() const { return channels.size(); }
};

int main() {
    YoutubeChannel ch1("TechTips", 10000);
    YoutubeChannel ch2("GamePlay", 5000);

    cout << "ch1 = " << ch1 << endl;
    cout << "ch2 = " << ch2 << endl;

    YoutubeChannel merged = ch1 + ch2;
    cout << "Merged channel = " << merged << endl;

    YoutubeChannel reduced = ch1 - 1000;
    cout << "ch1 after losing 1000 subs = " << reduced << endl;

    MyCollection myChannels;
    myChannels += ch1;
    myChannels += ch2;
    
    cout << "\n" << myChannels << endl;

    return 0;
}