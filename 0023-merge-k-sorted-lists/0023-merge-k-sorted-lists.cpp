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
    ListNode* mergeKLists(vector<ListNode*>& Array) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;

        for(int i=0; i<Array.size(); i++){
            if(Array[i]){
                pq.push({Array[i]->val, Array[i]}); //store the value of nodes
            }
        }

        ListNode* dummyNode = new ListNode(-1); // taking the dummy node as -1 before starting to merger the original nodes ex-> -1->1->1->2->3.....
        ListNode* temp = dummyNode;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            if(it.second->next) pq.push({it.second->next->val, it.second->next}); //if the next values in list exist..store that too.
            temp->next = it.second;
            temp = temp->next; //temp will traverse to every node
        }
        return dummyNode->next;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna