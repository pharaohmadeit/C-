//  Catch an Exception in a Constructor via Function try Blocks
//  main.cpp
//  fig12_05
//
//  Created by Pharaoh Tornes on 1/26/25.
//
#include <limits>
#include <stdexcept>
#include <format>
#include <iostream>

using namespace std;

//  class Integer purposely throws an exception from its constructor
class Integer {
public:
    //  explicit constructer call to prevent implicit conversion
    explicit Integer(int i) : value{i} {
        cout << format("Integer constructor: {}\n", value) << "Purposely throwing exception from Integer constructor\n";
        throw runtime_error("Integer constructor failed");
    }
private:
    int value{};
};

//  class ResourceManager uses function try block to catch exception
class ResourceManager {
public:
    ResourceManager(int i) try : myInteger(i) {
        cout << "ResourcManager constructor called\n";
    }
    catch (const runtime_error& exception) {
        cout << format("Exception while constructing ResourceManager: ", exception.what()) << "\nAutomatically rethrowing the exception\n";
        //  in this catch handler of the ResourceManager class one might include logging so that the error can be logged
        //  automatically rethrown the exception to main so there is an opportunity to deal with it
    }
private:
    Integer myInteger;
};

int main() {
    try {
        const ResourceManager resource{7};
    }
    catch (const runtime_error& exception) {
        cout << format("Rethrown exception caught in main: {}", exception.what()) << endl;
    }
}
