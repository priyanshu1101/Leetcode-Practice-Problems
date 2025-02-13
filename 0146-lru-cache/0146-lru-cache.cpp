class Node{
    public:
    int value;
    int key;
    Node* next;
    Node* prev;
    Node(int value,int key,Node* prev,Node* next){
        this->key=key;
        this->value=value;
        this->prev=prev;
        this->next=next;
    }
    void deleteFromPosition(){
        this->prev->next=this->next;
        this->next->prev=this->prev;
    }
    void addAtLast(Node* tail){
        tail->prev->next=this;
        this->prev=tail->prev;
        this->next=tail;
        tail->prev=this;
    }
};
class LRUCache {
public:
    unordered_map<int,Node*> record;
    Node* head;
    Node* tail;
    int capacity;
    LRUCache(int capacity) {
        this->capacity=capacity;
        head=new Node(-1,-1,NULL,NULL);
        tail=new Node(-1,-1,head,NULL);
        head->next=tail;
    }
    
    int get(int key) {
        if(record.find(key)!=record.end()){
            Node* nodeUsed=record[key];
            nodeUsed->deleteFromPosition();
            nodeUsed->addAtLast(tail);
            return nodeUsed->value;
        }else return -1;
    }
    
    void put(int key, int val) {
        if(record.find(key)!=record.end()){
            Node* nodeUsed=record[key];
            nodeUsed->value=val;

            nodeUsed->deleteFromPosition();
            nodeUsed->addAtLast(tail);
        }else{
            if(capacity==record.size())
            {
                Node* newNode = new Node(val,key,NULL,NULL);
                Node* nodeUsed = head->next;
                nodeUsed->deleteFromPosition();
                record.erase(nodeUsed->key);
                newNode->addAtLast(tail);
                record[key]=newNode;
            }
            else{
                Node* nodeUsed = new Node(val,key,NULL,NULL);
                record[key]=nodeUsed;
                nodeUsed->addAtLast(tail);
            }
        };

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */