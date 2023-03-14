/*
203 �Ƴ�����Ԫ��

����һ�������ͷ�ڵ� head ��һ������ val ��
����ɾ���������������� Node.val == val �Ľڵ㣬
������ �µ�ͷ�ڵ� ��
*/
// ֱ��ɾ��
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
// ����ͷ�ڵ�
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
707 �������
*/
class MyLinkedList {
public:
    // ��������ṹ��
    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode(int val) :val(val), next(nullptr) {}
    };
    // ��ʼ������
    MyLinkedList() {
        _dummyHead = new LinkedNode(0);
        _size = 0;
    }
    // ��ȡ����index���ڵ���ֵ�����index�ǷǷ���ֱֵ�ӷ���-1�� ע��index�Ǵ�0��ʼ�ģ���0���ڵ����ͷ���
    int get(int index) {
        if (index > (_size - 1) || index < 0) return -1;
        LinkedNode* cur = _dummyHead->next;
        while (index--) {
            cur = cur->next;
        }
        return cur->val;
    }
    // ��������ǰ�����һ���ڵ㣬������ɺ��²���Ľڵ�Ϊ������µ�ͷ���
    void addAtHead(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        _size++;
    }
    // ��������������һ���ڵ�
    void addAtTail(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = _dummyHead;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = newNode;
        _size++;
    }
    // �ڵ�index���ڵ�֮ǰ����һ���½ڵ㣬����indexΪ0����ô�²���Ľڵ�Ϊ�������ͷ�ڵ㡣
    // ���index ��������ĳ��ȣ���˵�����²���Ľڵ�Ϊ�����β���
    // ���index��������ĳ��ȣ��򷵻ؿ�
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
    // ɾ����index���ڵ㣬���index ���ڵ�������ĳ��ȣ�ֱ��return��ע��index�Ǵ�0��ʼ��
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
    // ��ӡ����
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

/*
 206 ��ת����
*/
// ˫ָ��
{
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* temp; // ����cur����һ���ڵ�
        while (cur) {
            temp = cur->next; // ����һ�� cur����һ���ڵ㣬��Ϊ������Ҫ�ı�cur->next
            cur->next = pre; // ��ת����
            // ����pre �� curָ��
            pre = cur;
            cur = temp;
        }
        return pre;
    }
}

/*
24     �������������еĽڵ�
*/
{
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0); // ����һ������ͷ���
        dummyHead->next = head; // ������ͷ���ָ��head���������������ɾ������
        ListNode* cur = dummyHead;
        while (cur->next != nullptr && cur->next->next != nullptr) {
            ListNode* tmp = cur->next; // ��¼��ʱ�ڵ�
            ListNode* tmp1 = cur->next->next->next; // ��¼��ʱ�ڵ�

            cur->next = cur->next->next;    // ����һ
            cur->next->next = tmp;          // �����
            cur->next->next->next = tmp1;   // ������

            cur = cur->next->next; // cur�ƶ���λ��׼����һ�ֽ���
        }
        return dummyHead->next;
    }
}

/*
19    ɾ������ĵ�����N���ڵ�
*/
{
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* slow = dummyHead;
        ListNode* fast = dummyHead;
        while (n-- && fast != NULL) {
            fast = fast->next;
        }
        fast = fast->next; // fast����ǰ��һ������Ϊ��Ҫ��slowָ��ɾ���ڵ����һ���ڵ�
        while (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;

        ListNode *tmp = slow->next;  C++�ͷ��ڴ���߼�
        slow->next = tmp->next;
        delete nth;

        return dummyHead->next;
    }
}

/*
142     ��������||
*/
{
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            // ����ָ����������ʱ��head �� �����㣬ͬʱ����ֱ������
            if (slow == fast) {
                ListNode* index1 = fast;
                ListNode* index2 = head;
                while (index1 != index2) {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index2; // ���ػ������
            }
        }
        return NULL;
    }
}