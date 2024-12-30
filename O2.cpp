#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <vector>

enum present_type {socks, cat, dog, smartphone};

class xmas_object {
    public:
        virtual void do_something() = 0;
};

class present : public xmas_object {
    private:
        present_type type;

    public:
        present(present_type t) : type(t) {}
        
        std::string get_present_name() {
            switch (type) {
                case socks: return "socks";
                case cat: return "cat";
                case dog: return "dog";
                case smartphone: return "smartphone";
                default: return "unknown";
            }
        }
        void do_something() override {
            std::cout << "This is a " << get_present_name() << "!" << std::endl;

        }
};

class xmas_tree : public xmas_object {
    private:
        std::vector<present*> presents;

    public:
        void do_something() override {
             std::cout << "There are " << presents.size() << " presents under the tree!" << std::endl;
             for (present* p : presents) {
                std::cout << p->get_present_name() << " ";
             }
             std::cout << std::endl;
        }
        void add_present(present* new_present) {
            presents.push_back(new_present);
        }
        present* remove_present() {
            if (!presents.empty()) {
                present* first_present = presents.front();
                presents.erase(presents.begin());
                return first_present;
            }
            return nullptr;
        } 
};

class santaclaus : public xmas_object {
    private:
        xmas_tree* tree;
    
    public:
        santaclaus(xmas_tree* tree) : tree(tree) {}

        void do_something() override{
            present* new_present = new present(static_cast<present_type>(rand() % 4));
            tree->add_present(new_present);
            std::cout << "Ho ho ho! I have come to bring a new present (" << new_present->get_present_name() << ")!" << std::endl;
        }
};

class child : public xmas_object {
    private:
        std::vector<present*> my_presents;
    
    public:
        void receive_present(present* p) {
            if (p) {
                my_presents.push_back(p);
                std::cout << "HURRAY! I got a " << p->get_present_name() << "!" << std::endl;
            } else {
                std::cout << "Oh no! There are no presents left under the tree!" << std::endl;
            }
        }
        void do_something() {
            std::cout << "I will try to get another present!" << std::endl;

        }
        void show_presents() {
            std::cout << "Here are all the presents I have so far:" << std::endl;
            for (present* p : my_presents) {
                std::cout << " - " << p->get_present_name() << std::endl;
            }
        }
};

int main() {
    srand(time(NULL));

    int num_children;
    std::cout << "Welcome to the Xmas simulator!" << std::endl;
    std::cout << "How many children do you want to simulate? ";
    std::cin >> num_children;
    std::cout << std::endl;
    

    xmas_tree tree;
    santaclaus santa(&tree);
    std::vector<child> children(num_children);

    for (int i = 0; i < 5; ++i) {
        tree.add_present(new present(static_cast<present_type>(rand() % 4)));
    }

    while(true) {
        int z = rand() % (2 + num_children);
        
        if (z == 0) {
            tree.do_something();
        } else if (z == 1) {
            santa.do_something();
        } else {
            int child_index = z - 2;
            std::cout << "Child " << child_index << ":" << std::endl;
            children[child_index].receive_present(tree.remove_present());
        }

        _getch();
    } 
}