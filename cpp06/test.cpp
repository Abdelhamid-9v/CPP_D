#include <iostream>
#include <exception>
#include <typeinfo>

// --- CLASSES FOR TESTING ---
class Base {
public:
    virtual ~Base() {} // Essential: Must be polymorphic
};

class A : public Base {};
class B : public Base {};

// --- MAIN ---
int main() {
    // Setup: Create an object of type A, but hold it as a Base pointer/reference
    Base* ptr = new A();      // Pointer to A
    Base& ref = *ptr;         // Reference to A
    
    std::cout << "--- OBJECT CREATED: Type A ---" << std::endl;

    // ==========================================
    // VALID CASE 1: Pointer to Pointer (* -> *)
    // Returns NULL on failure.
    // ==========================================
    std::cout << "\n[CASE 1: Pointer -> Pointer]" << std::endl;
    
    // Success scenario (Base* -> A*)
    A* a_ptr = dynamic_cast<A*>(ptr);
    if (a_ptr) 
        std::cout << "  Success: Cast to A* worked." << std::endl;

    // Failure scenario (Base* -> B*)
    B* b_ptr = dynamic_cast<B*>(ptr);
    if (b_ptr == NULL) 
        std::cout << "  Failure: Cast to B* returned NULL (Correct behavior)." << std::endl;


    // ==========================================
    // VALID CASE 2: Reference to Reference (& -> &)
    // Throws std::bad_cast on failure.
    // ==========================================
    std::cout << "\n[CASE 2: Reference -> Reference]" << std::endl;

    // Success scenario (Base& -> A&)
    try {
        A& a_ref = dynamic_cast<A&>(ref);
        std::cout << "  Success: Cast to A& worked." << std::endl;
        (void)a_ref; // Silence unused warning
    } catch (std::exception& e) {
        std::cout << "  Error: " << e.what() << std::endl;
    }

    // Failure scenario (Base& -> B&)
    try {
        B& b_ref = dynamic_cast<B&>(ref);
        (void)b_ref;
    } catch (std::exception& e) {
        std::cout << "  Failure: Cast to B& threw exception: " << e.what() << " (Correct behavior)." << std::endl;
    }


    // ==========================================
    // VALID CASE 3: Pointer to Reference (*ptr -> &)
    // You must dereference (*ptr) to treat it as an object source.
    // ==========================================
    std::cout << "\n[CASE 3: *ptr -> Reference]" << std::endl;

    try {
        // Note the * before ptr inside the parentheses
        A& a_ref_from_ptr = dynamic_cast<A&>(*ptr);
        std::cout << "  Success: Cast (*ptr) to A& worked." << std::endl;
        (void)a_ref_from_ptr;
    } catch (std::exception& e) {
        std::cout << "  Error: " << e.what() << std::endl;
    }


    // ==========================================
    // VALID CASE 4: Reference to Pointer (&ref -> *)
    // You must take address (&ref) to treat it as a pointer source.
    // ==========================================
    std::cout << "\n[CASE 4: &ref -> Pointer]" << std::endl;

    // Note the & before ref inside the parentheses
    A* a_ptr_from_ref = dynamic_cast<A*>(&ref);
    if (a_ptr_from_ref)
        std::cout << "  Success: Cast (&ref) to A* worked." << std::endl;


    // ==========================================
    // SPECIAL CASE: void*
    // ==========================================
    std::cout << "\n[CASE 5: void* Cast]" << std::endl;
    void* raw = dynamic_cast<void*>(ptr);
    std::cout << "  Success: Obtained raw address: " << raw << std::endl;


    // ==========================================
    // INVALID CASES (Will not compile if uncommented)
    // ==========================================
    std::cout << "\n[INVALID CASES - Compilation Errors]" << std::endl;

    /* // ERROR: You cannot feed a POINTER to a REFERENCE cast
    A& fail1 = dynamic_cast<A&>(ptr); 
    
    // ERROR: You cannot feed a REFERENCE/OBJECT to a POINTER cast
    A* fail2 = dynamic_cast<A*>(ref); 
    */
    
    std::cout << "  (Uncomment lines in code to see build errors)" << std::endl;

    delete ptr;
    return 0;
}