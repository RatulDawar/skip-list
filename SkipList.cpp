struct Node{
    int val;
    Node *next;
    Node *prev;
    Node *down;
    Node(int val){
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
        this->down = NULL;
    }
};

class Skiplist {
    private:
        //topmost level head and tail
        Node *lastLevelHead;
        Node *lastLevelTail;
        int levels; 
        bool shouldPromote(){
            return rand()%2;
        }

        void connectNodesVertically(Node *lowerLevel,Node *higherLevel){
            higherLevel->down = lowerLevel;
        }

        // add new level
        void addNewLevel(){
            Node * head = new Node(INT_MIN);
            Node *tail = new Node(INT_MAX);
            head->next = tail;
            tail->prev = head;
            if(levels > 0){
                connectNodesVertically(lastLevelHead,head);
                connectNodesVertically(lastLevelTail,tail);
            }
            lastLevelTail = tail;
            lastLevelHead = head;
            levels++;
        }

        // insert the provided node next to the given node
        void insertNextTo(Node *node,Node *newNode){
            Node *nxt = node->next;
            
            node->next = newNode;
            newNode->prev = node;
        
            newNode->next = nxt;
            nxt->prev = newNode;
        }

        //insert the node in the provided list
        void insertInList(Node *head, Node *newNode){
            Node *iterator = head;
            while(iterator->next->val < newNode->val){
                iterator = iterator->next;
            }
            
            insertNextTo(iterator,newNode);
        }


        // returns pointer to the node just less than or equal to the given node
        Node* lowerBound(Node *head, int val){
            Node *iterator = head;
            while(iterator->next->val <  val){
                iterator = iterator->next;   
            }
            return iterator->next->val == val ? iterator->next : iterator;
        }


        void erase(Node *node){
            Node *prev = node->prev;
            Node *nxt = node->next;

            prev->next = nxt;
            nxt->prev = prev;

        }


    public:
        Skiplist() {
            lastLevelTail = NULL;
            lastLevelHead = NULL;
            levels = 0;
            addNewLevel();
            
        }
        
        // returns pointer to the target node else returns null
        Node* searchHelper(int target){
            Node * searchStartNode = lastLevelHead;
            while(searchStartNode){
                Node *lowerBound = this->lowerBound(searchStartNode,target);
                if(lowerBound->val == target)
                    return lowerBound;
                searchStartNode = searchStartNode->down;
            }
            return NULL;
        }

        bool search(int target) {
            return (searchHelper(target) != NULL); 
        }
        
        void add(int num) {
            int levelIndex = 0;
            Node *newNode = new Node(num);
            int isPromoted = true; // always true for first level
            while(isPromoted){
                if(levelIndex >= this->levels)addNewLevel();
                insertInList(lastLevelHead,newNode);
                isPromoted = shouldPromote();
                if(isPromoted){
                    Node *newNodeNextLevel = new Node(num);
                    connectNodesVertically(newNode,newNodeNextLevel);
                    newNode = newNodeNextLevel;
                }
                
            }
        }
        
        bool erase(int num) {
            Node * toErase = searchHelper(num);
            if(!toErase)
                return false;

            while(toErase){
                erase(toErase);
                toErase = toErase->down;
            }

            return true;
        }
};
