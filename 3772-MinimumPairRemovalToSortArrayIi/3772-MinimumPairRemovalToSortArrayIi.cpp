// Last updated: 6/24/2026, 3:29:56 AM
using ll = long long;

class Node {
public:
    ll val;
    int idx;
    bool del = false;

    Node *next = NULL, *prev = NULL;

    Node(ll x, int i) : val(x), idx(i) {}
};

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {

        int n = nums.size();
        if(n == 1) return 0;

        Node *head = new Node(LLONG_MIN, -1);
        Node *tail = new Node(LLONG_MAX, n);

        Node *pr = head;

        priority_queue<pair<array<ll,2>, array<Node*,2>>> pq;

        int bad = 0;

        for(int i = 0; i < n; i++){

            auto node = new Node(nums[i], i);

            pr->next = node;
            node->prev = pr;

            if(pr != head){

                pq.push({
                    {-pr->val - node->val, -pr->idx},
                    {pr, node}
                });

                if(pr->val > node->val) bad++;
            }

            pr = node;
        }

        pr->next = tail;
        tail->prev = pr;

        auto inv = [&](Node *a, Node *b){
            if(a == head || b == tail) return false;
            return (a->val > b->val);
        };

        int ans = 0;

        while(bad){

            auto [x, y] = pq.top(); pq.pop();

            auto &[sum, idx] = x;
            auto &[l, r] = y;

            if(l->del || r->del) continue;

            auto L = l->prev;
            auto R = r->next;

            bad -= inv(L, l) + inv(l, r) + inv(r, R);
            l->del = r->del = true;

            auto node = new Node(-sum, l->idx);


            L->next = R->prev = node;
            node->prev = L;
            node->next = R;

            bad += inv(L, node) + inv(node, R);

            if(L != head)
                pq.push({
                    {-L->val - node->val, -L->idx},
                    {L, node}
                });

            if(R != tail)
                pq.push({
                    {-node->val - R->val, -node->idx},
                    {node, R}
                });

            ans++;
        }

        return ans;
    }
};