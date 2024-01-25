#include <msclr\auto_gcroot.h> // Header file for auto_gcroot

using namespace System;

// Define a managed class
public ref class HelloWorld {
public:
    // Managed method
    void DisplayMessage() {
        Console::WriteLine("Hello, .NET Framework from C++/CLI!");
    }
};

int main() {
    // Initialize the CLR
    Console::WriteLine("Initializing CLR...");
    System::Threading::Thread::CurrentThread->ApartmentState = System::Threading::ApartmentState::STA;
    msclr::auto_gcroot<HelloWorld^> helloWorld = gcnew HelloWorld();

    // Call the managed method
    helloWorld->DisplayMessage();

    return 0;
}
