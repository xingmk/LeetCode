class Sloution {
private:
	// Definition for singly-linked list.
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(NULL) {}
	};

public:
	/*
	  203 移除链表元素
	 */
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
	
	/*
	  206 反转链表
	 */
	ListNode* reverseList(ListNode* head) {
		ListNode* pre = nullptr;
		ListNode* cur = head;
		ListNode* temp; // 保存cur的下一个节点
		while (cur) {
			temp = cur->next; // 保存一下 cur的下一个节点，因为接下来要改变cur->next
			cur->next = pre; // 翻转操作
			// 更新pre 和 cur指针
			pre = cur;
			cur = temp;
		}
		return pre;
	}
	
	/*
	  24     两两交换链表中的节点
	 */
	ListNode* swapPairs(ListNode* head) {
		ListNode* dummyHead = new ListNode(0); // 设置一个虚拟头结点
		dummyHead->next = head; // 将虚拟头结点指向head，这样方面后面做删除操作
		ListNode* cur = dummyHead;
		while (cur->next != nullptr && cur->next->next != nullptr) {
			ListNode* tmp = cur->next; // 记录临时节点
			ListNode* tmp1 = cur->next->next->next; // 记录临时节点
			
			cur->next = cur->next->next;    // 步骤一
			cur->next->next = tmp;          // 步骤二
			cur->next->next->next = tmp1;   // 步骤三
			
			cur = cur->next->next; // cur移动两位，准备下一轮交换
		}
		return dummyHead->next;
	}
	
	/*
	  19    删除链表的倒数第N个节点
	 */
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* dummyHead = new ListNode(0);
		dummyHead->next = head;
		ListNode* slow = dummyHead;
		ListNode* fast = dummyHead;
		while (n-- && fast != NULL) {
			fast = fast->next;
		}
		fast = fast->next; // fast再提前走一步，因为需要让slow指向删除节点的上一个节点
		while (fast != NULL) {
			fast = fast->next;
			slow = slow->next;
		}
		slow->next = slow->next->next;
		
		return dummyHead->next;
	}
	
	/*
	  142     环形链表||
	 */
	ListNode *detectCycle(ListNode *head) {
		ListNode* fast = head;
		ListNode* slow = head;
		while(fast != NULL && fast->next != NULL) {
			slow = slow->next;
			fast = fast->next->next;
			// 快慢指针相遇，此时从head 和 相遇点，同时查找直至相遇
			if (slow == fast) {
				ListNode* index1 = fast;
				ListNode* index2 = head;
				while (index1 != index2) {
					index1 = index1->next;
					index2 = index2->next;
				}
				return index2; // 返回环的入口
			}
		}
		return nullptr;
	}

};
