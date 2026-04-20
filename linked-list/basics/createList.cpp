#include <string>

struct DoubleListNode {
    std::string data;
    DoubleListNode* next;
    DoubleListNode* prev;
    DoubleListNode(std::string val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    };
    DoubleListNode() {
        data = "default";
        next = nullptr;
        prev = nullptr;
    }
};


int main() {
    DoubleListNode* doubleLinkedList = new DoubleListNode("abel");
    


    return 0;
}