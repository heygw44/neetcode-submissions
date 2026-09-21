class Solution {
public:
    void reorderList(ListNode* head) {
        // 노드가 0개 또는 1개면 바꿀 것이 없다.
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        // 1. 가운데 찾기
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // slow 뒤쪽부터 두 번째 리스트로 분리
        ListNode* second = slow->next;
        slow->next = nullptr;

        // 2. 두 번째 리스트 뒤집기
        ListNode* prev = nullptr;

        while (second != nullptr) {
            ListNode* nextNode = second->next; // 다음 노드 기억
            second->next = prev;               // 방향 뒤집기
            prev = second;                     // prev 이동
            second = nextNode;                 // second 이동
        }

        // 뒤집힌 리스트의 시작점
        second = prev;

        // 3. 앞쪽과 뒤쪽을 번갈아 연결
        ListNode* first = head;

        while (second != nullptr) {
            ListNode* firstNext = first->next;
            ListNode* secondNext = second->next;

            first->next = second;
            second->next = firstNext;

            first = firstNext;
            second = secondNext;
        }
    }
};