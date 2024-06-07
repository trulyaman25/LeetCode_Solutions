class node {
    public:
        int value = 0;
        node* next;
    
    public:
        node(int data, node* nextNode = nullptr){
            value = data;
            next = nextNode;
        }

        node(){
            value = 0;
            next = nullptr;
        }
};

class MyLinkedList {
    public:
        node* head;
        int length;

        MyLinkedList() {
            head = nullptr;
            length = 0;
        }
        
        int get(int index) {
            if (index < 0 || index >= length) {
                return -1;
            }
            node* tempHead = head;
            for (int i = 0; i < index; i++) {
                tempHead = tempHead->next;
            }
            return tempHead->value;
        }
        
        void addAtHead(int val) {
            node* newNode = new node(val, head);
            head = newNode;
            length++;
        }
        
        void addAtTail(int val) {
            node* newNode = new node(val);
            if (head == nullptr) {
                head = newNode;
            } else {
                node* tempHead = head;
                while (tempHead->next != nullptr) {
                    tempHead = tempHead->next;
                }
                tempHead->next = newNode;
            }
            length++;
        }
        
        void addAtIndex(int index, int val) {
            if (index < 0 || index > length) {
                return;
            }
            
            if (index == 0) {
                addAtHead(val);
            } else if (index == length) {
                addAtTail(val);
            } else {
                node* tempHead = head;
                for (int i = 0; i < index - 1; i++) {
                    tempHead = tempHead->next;
                }
                node* newNode = new node(val, tempHead->next);
                tempHead->next = newNode;
                length++;
            }
        }
        
        void deleteAtIndex(int index) {
            if (index < 0 || index >= length) {
                return;
            }
            if (index == 0) {
                node* tempHead = head;
                head = head->next;
                delete tempHead;
            } else {
                node* tempHead = head;
                for (int i = 0; i < index - 1; i++) {
                    tempHead = tempHead->next;
                }
                node* nodeToDelete = tempHead->next;
                tempHead->next = nodeToDelete->next;
                delete nodeToDelete;
            }
            length--;
        }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
