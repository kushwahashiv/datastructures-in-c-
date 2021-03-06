// Source : https://leetcode.com/problems/reverse-nodes-in-k-group/description/
// Author : Shiv S. Kushwaha
// Date   : 2014-07-05

/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
You may not alter the values in the nodes, only nodes itself may be changed.
Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5
For k = 2, you should return: 2->1->4->3->5
For k = 3, you should return: 3->2->1->4->5
*/

#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

/*
-1 -> 1 -> 2 -> 3 -> 4 -> 5
 |    |    |    |
pre  cur  nex  tmp

-1 -> 2 -> 1 -> 3 -> 4 -> 5
 |         |    |    |
pre       cur  nex  tmp

-1 -> 3 -> 2 -> 1 -> 4 -> 5
 |              |    |    |
pre            cur  nex  tmp
*/

ListNode *reverseKGroup(ListNode *head, int k) {
  if (head == NULL || k == 1) return head;
  int num = 0;
  ListNode *preheader = new ListNode(-1);
  preheader->next = head;
  ListNode *cur = preheader, *nex, *pre = preheader;
  while (cur = cur->next)
    num++;
  while (num >= k) {
    cur = pre->next;
    nex = cur->next;
    for (int i = 1; i < k; ++i) {
      cur->next = nex->next;
      nex->next = pre->next;
      pre->next = nex;
      nex = cur->next;
    }
    pre = cur;
    num -= k;
  }
  return preheader->next;
}

void printList(ListNode* h)
{
  while (h != nullptr) {
    printf("%d ", h->val);
    h = h->next;
  }
  printf("\n");
}

ListNode* createList(int a[], int n)
{
  ListNode *head = nullptr, *p = nullptr;
  for (int i = 0; i < n; i++) {
    if (head == nullptr) {
      head = p = new ListNode(a[i]);
    }
    else {
      p->next = new ListNode(a[i]);
      p = p->next;
    }
  }
  return head;
}



int main(int argc, char** argv)
{
  int a[] = { 1,2,3,4,5,6,7,8,9,10 };
  ListNode* pList = createList(a, sizeof(a) / sizeof(int));

  int k = 2;
  if (argc > 1) {
    k = atoi(argv[1]);
  }

  pList = reverseKGroup(pList, k);
  printList(pList);

  return 0;
}
