class node {
    public:
        node* previousNode;
        string url;
        node* nextNode;
    
    public:
        node(node* previous, string name, node* next){
            previousNode = previous;
            url = name;
            nextNode = next;
        }

        node(string name){
            previousNode = NULL;
            url = name;
            nextNode = NULL;
        }

        node(node* previous, string name){
            previousNode = previous;
            url = name;
            nextNode = NULL;
        }

        node(string name, node* next){
            previousNode = NULL;
            url = name;
            nextNode = next;
        }
};

class BrowserHistory {
public:
    node* homePage = NULL;

    BrowserHistory(string homepage) {
        homePage = new node(homepage);
    }
    
    void visit(string url) {
        node* current = new node(url);
        homePage->nextNode = current;
        current->previousNode = homePage;
        homePage = homePage->nextNode;
    }
    
    string back(int steps) {
        while(homePage->previousNode && steps){
            steps--;
            homePage = homePage->previousNode;
        }
        return homePage->url;
    }
    
    string forward(int steps) {
        int count = 0;
        while(homePage->nextNode && count < steps){
            count++;
            homePage = homePage->nextNode;
        }
        return homePage->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */