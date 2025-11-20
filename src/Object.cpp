#include <iostream>

class Object {
    public: 
        virtual ~Object() {}
        virtual void onStep();
};

// Provide a default implementation for the virtual method so the vtable
// and symbol are emitted at link time.
void Object::onStep() {
    // default: do nothing
}