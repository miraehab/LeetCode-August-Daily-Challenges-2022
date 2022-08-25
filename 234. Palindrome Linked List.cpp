/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* tmp = head;
        ListNode* tmp2 = head;
        int len = 0;
        while(tmp != nullptr){
            ++len;
            tmp = tmp -> next;
        }
        stack<int> st;
        int i = 1;
        bool odd = false;
        if(len%2 != 0) odd = true;
        while(tmp2 != nullptr && i <= len){
            if(i <= len/2){
                st.push(tmp2->val);
            }else{
                if(odd && i == (len/2)+1){
                    ++i;
                    tmp2 = tmp2->next;
                    continue;
                }
                
                int top = st.top();
                st.pop();
                if(tmp2->val != top) return false;
            }
            tmp2 = tmp2->next;
            ++i;
        }
        return true;
    }
};