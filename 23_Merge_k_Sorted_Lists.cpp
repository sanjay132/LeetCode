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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        ListNode *head;
        ListNode *dummy = new ListNode();
        head = dummy;

        // comparator function for the min Heap
        auto cmp = [](const ListNode *p1, const ListNode *p2){
            return p1->val > p2->val;
        };
        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> inHeap(cmp);
 
        // put the first val and head Node of all the sublist in to 
        // the heap
        for(int i=0; i<lists.size(); i++){
            if(lists[i]){
                //inHeap.push({lists[i]->val,lists[i]});    
                inHeap.push(lists[i]);
            }
        }
        
        // Now keep poping the top element of the 
        // heap and add to the dummyList
        while(inHeap.size()){
            auto top = inHeap.top();
            inHeap.pop();
 
            head->next = top;
            head = head->next;
            if(top->next){
                inHeap.push(top->next);
            }
        }
        return dummy->next;
/*
        // <val of the list Node, ith List>
        using p = pair<int,ListNode *>;
        ListNode *head;
        ListNode *dummy = new ListNode();
        head = dummy;
        // comparator function for the min Heap
        auto cmp = [](const p &p1, const p &p2){
            return p1.first > p2.first;
        };
        priority_queue<p, vector<p>, decltype(cmp)> inHeap(cmp);
 
        // put the first val and head Node of all the sublist in to 
        // the heap
        for(int i=0; i<lists.size(); i++){
            if(lists[i]){
                inHeap.push({lists[i]->val,lists[i]});    
            }
        }
        
        // Now keep poping the top element of the 
        // heap and add to the dummyList
        while(inHeap.size()){
            auto top = inHeap.top();
            inHeap.pop();
 
            head->next = top.second;
            head = head->next;
            if(top.second->next){
                inHeap.push({top.second->next->val, top.second->next});
            }
        }
        return dummy->next;
*/
    }
};