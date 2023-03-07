/*
203 移除链表元素

给你一个链表的头节点 head 和一个整数 val ，
请你删除链表中所有满足 Node.val == val 的节点，
并返回 新的头节点 。
*/
// 直接删除
ListNode* removeElements(ListNode* head, int val) {
    // Head node
    while (head != NULL && head->val == val) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
    // Not Head node
    ListNode* cur = head;
    while (cur != NULL && cur->next != NULL) {
        if (cur->next->val == val) {
            ListNode* temp = cur->next;
            cur->next = cur->next->next;
            delete temp;
        }
        else {
            cur = cur->next;
        }
    }
    return head;
}
// 虚拟头节点
ListNode* removeElements(ListNode* head, int val) {
    ListNode* dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode* cur = dummyHead;
    while (cur->next != NULL) {
        if (cur->next->val == val) {
            cur->next = cur->next->next;
        }
        else {
            cur = cur->next;
        }
    }
    return dummyHead->next;
}

/*
707 设计链表
*/
class MyLinkedList {
public:
    // 定义链表结构体
    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode(int val) :val(val), next(nullptr) {}
    };
    // 初始化链表
    MyLinkedList() {
        _dummyHead = new LinkedNode(0);
        _size = 0;
    }
    // 获取到第index个节点数值，如果index是非法数值直接返回-1， 注意index是从0开始的，第0个节点就是头结点
    int get(int index) {
        if (index > (_size - 1) || index < 0) return -1;
        LinkedNode* cur = _dummyHead->next;
        while (index--) {
            cur = cur->next;
        }
        return cur->val;
    }
    // 在链表最前面插入一个节点，插入完成后，新插入的节点为链表的新的头结点
    void addAtHead(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        _size++;
    }
    // 在链表最后面添加一个节点
    void addAtTail(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = _dummyHead;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = newNode;
        _size++;
    }
    // 在第index个节点之前插入一个新节点，例如index为0，那么新插入的节点为链表的新头节点。
    // 如果index 等于链表的长度，则说明是新插入的节点为链表的尾结点
    // 如果index大于链表的长度，则返回空
    void addAtIndex(int index, int val) {
        if (index > _size) return;
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = _dummyHead;
        while (index--) {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        _size++;
    }
    // 删除第index个节点，如果index 大于等于链表的长度，直接return，注意index是从0开始的
    void deleteAtIndex(int index) {
        if (index > _size - 1 || index < 0) return;
        LinkedNode* cur = _dummyHead;
        while (index--) {
            cur = cur->next;
        }
        LinkedNode* temp = cur->next;
        cur->next = cur->next->next;
        delete temp;
        _size--;
    }
    // 打印链表
    void printLinkedList() {
        LinkedNode* cur = _dummyHead;
        while (cur->next != nullptr) {
            cout << cur->next->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
private:
    int _size;
    LinkedNode* _dummyHead;

};