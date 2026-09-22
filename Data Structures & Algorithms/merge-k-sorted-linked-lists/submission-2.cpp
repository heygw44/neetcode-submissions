class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // val이 작은 노드가 먼저 나오도록 하는 최소 힙
        auto compare = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };

        priority_queue<
            ListNode*,
            vector<ListNode*>,
            decltype(compare)
        > pq(compare);

        // 각 리스트의 첫 노드만 힙에 넣기
        for (ListNode* node : lists) {
            if (node != nullptr) {
                pq.push(node);
            }
        }

        ListNode dummy(0);      // 결과 리스트의 가짜 시작 노드
        ListNode* tail = &dummy;

        while (!pq.empty()) {
            ListNode* smallest = pq.top();
            pq.pop();

            // 가장 작은 노드를 결과 뒤에 연결
            tail->next = smallest;
            tail = tail->next;

            // 방금 꺼낸 노드의 다음 노드를 힙에 추가
            if (smallest->next != nullptr) {
                pq.push(smallest->next);
            }
        }

        return dummy.next;
    }
};