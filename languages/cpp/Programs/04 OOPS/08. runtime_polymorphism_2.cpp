#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Instrument {
    public:
        virtual void play() {
            cout << "Playing instrument" << endl;
        }
};

class Guitar : public Instrument {
    public:
        void play() {
            cout << "Playing guitar" << endl;
        }
};

class Piano : public Instrument {
    public:
        void play() {
            cout << "Playing piano" << endl;
        }
};

class Drums : public Instrument {
    public:
        void play() {
            cout << "Playing drums" << endl;
        }
};

class Violin : public Instrument {
    public:
        void play() {
            cout << "Playing violin" << endl;
        }
};


int main() {
    // Note: Using shared_ptr which supports copy semantics and initializer list

    vector<shared_ptr<Instrument>> instruments = {
        make_shared<Guitar>(),
        make_shared<Piano>(),
        make_shared<Drums>(),
        make_shared<Violin>()
    };

    for (const shared_ptr<Instrument>& instrument : instruments) {
        instrument->play();
    }
    // No manual cleanup needed - shared_ptr handles memory management automatically
    
    return 0;
}