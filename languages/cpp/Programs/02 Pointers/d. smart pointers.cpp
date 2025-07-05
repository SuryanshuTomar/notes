#include <iostream>
#include <memory>

class TestClass {
private:
    int value;
    std::string name;

public:
    TestClass(int val, const std::string& n) : value(val), name(n) {
        std::cout << "Constructor called for " << name << " with value " << value << std::endl;
    }
    
    ~TestClass() {
        std::cout << "Destructor called for " << name << " with value " << value << std::endl;
    }
    
    void display() {
        std::cout << "Object " << name << " has value: " << value << std::endl;
    }
    
    void setValue(int val) {
        value = val;
    }
};

void demonstrateUniquePtr() {
    std::cout << "\n=== UNIQUE_PTR DEMONSTRATION ===\n";
    
    // Creating unique_ptr
    std::unique_ptr<TestClass> uniquePtr = std::make_unique<TestClass>(10, "UniqueObj");
    uniquePtr->display();
    
    // Moving ownership
    std::unique_ptr<TestClass> movedPtr = std::move(uniquePtr);
    
    if (!uniquePtr) {
        std::cout << "Original unique_ptr is now null after move\n";
    }
    
    movedPtr->display();
    
    std::cout << "Leaving unique_ptr scope...\n";
    // Destructor will be called automatically when leaving scope
}

void demonstrateSharedPtr() {
    std::cout << "\n=== SHARED_PTR DEMONSTRATION ===\n";
    
    std::shared_ptr<TestClass> sharedPtr1 = std::make_shared<TestClass>(20, "SharedObj");
    std::cout << "Reference count: " << sharedPtr1.use_count() << std::endl;
    
    {
        std::shared_ptr<TestClass> sharedPtr2 = sharedPtr1;
        std::cout << "Reference count after copying: " << sharedPtr1.use_count() << std::endl;
        sharedPtr2->display();
        
        std::cout << "Leaving inner scope...\n";
    }
    
    std::cout << "Reference count after inner scope: " << sharedPtr1.use_count() << std::endl;
    sharedPtr1->display();
    
    std::cout << "Leaving shared_ptr scope...\n";
    // Destructor will be called when reference count reaches 0
}

void demonstrateWeakPtr() {
    std::cout << "\n=== WEAK_PTR DEMONSTRATION ===\n";
    
    std::shared_ptr<TestClass> sharedPtr = std::make_shared<TestClass>(30, "WeakObj");
    std::weak_ptr<TestClass> weakPtr = sharedPtr;
    
    std::cout << "Shared ptr reference count: " << sharedPtr.use_count() << std::endl;
    std::cout << "Weak ptr expired: " << (weakPtr.expired() ? "Yes" : "No") << std::endl;
    
    // Using weak_ptr safely
    if (auto lockedPtr = weakPtr.lock()) {
        lockedPtr->display();
        std::cout << "Successfully accessed object through weak_ptr\n";
    }
    
    // Reset shared_ptr
    sharedPtr.reset();
    std::cout << "Shared ptr reset...\n";
    std::cout << "Weak ptr expired: " << (weakPtr.expired() ? "Yes" : "No") << std::endl;
    
    // Try to access through weak_ptr after object is destroyed
    if (auto lockedPtr = weakPtr.lock()) {
        lockedPtr->display();
    } else {
        std::cout << "Cannot access object through weak_ptr - object has been destroyed\n";
    }
}

int main() {
    std::cout << "Smart Pointers Demonstration\n";
    std::cout << "============================\n";
    
    demonstrateUniquePtr();
    demonstrateSharedPtr();
    demonstrateWeakPtr();
    
    std::cout << "\n=== PROGRAM ENDED ===\n";
    return 0;
}