#include <bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* solucion(ListNode* head, int x) {
        // Listas auxiliares: una para < x y otra para >= x
        ListNode lessDummy(0), geDummy(0);
        ListNode *lt = &lessDummy, *ge = &geDummy;

        for (ListNode* p = head; p != nullptr; ) {
            ListNode* nxt = p->next;   // guarda el siguiente
            p->next = nullptr;         // desacopla el nodo actual

            if (p->val < x) {
                lt->next = p;          // agrega al final de la lista < x
                lt = lt->next;
            } else {
                ge->next = p;          // agrega al final de la lista >= x
                ge = ge->next;
            }
            p = nxt;
        }

        // Conecta ambas listas, asegurando terminación en null
        lt->next = geDummy.next;
        ge->next = nullptr;

        return lessDummy.next;          // nueva cabeza
    }
};


/* -------- Helpers -------- */
ListNode* buildList(const vector<int>& a) {
    ListNode dummy;
    ListNode* tail = &dummy;
    for (int v : a) { tail->next = new ListNode(v); tail = tail->next; }
    return dummy.next;
}
vector<int> listToVec(ListNode* head) {
    vector<int> v; for (auto* p = head; p; p = p->next) v.push_back(p->val);
    return v;
}
void freeList(ListNode* head) {
    while (head) { auto* q = head->next; delete head; head = q; }
}
template <class It, class Pred>
vector<typename iterator_traits<It>::value_type> subseq(It b, It e, Pred pred) {
    using T = typename iterator_traits<It>::value_type;
    vector<T> out; for (; b != e; ++b) if (pred(*b)) out.push_back(*b);
    return out;
}

/* Validaciones de la partición estable */
void validate_partition(const vector<int>& original, int x, ListNode* result) {
    vector<int> res = listToVec(result);

    // Propiedad: todos los <x antes que cualquier >=x
    bool seen_ge = false;
    for (int v : res) {
        if (v >= x) seen_ge = true;
        if (seen_ge && v < x) assert(false && "Aparece un <x después de >=x");
    }

    // Estabilidad en cada grupo
    auto orig_lt = subseq(original.begin(), original.end(), [&](int v){return v < x;});
    auto orig_ge = subseq(original.begin(), original.end(), [&](int v){return v >= x;});
    auto res_lt  = subseq(res.begin(),      res.end(),      [&](int v){return v < x;});
    auto res_ge  = subseq(res.begin(),      res.end(),      [&](int v){return v >= x;});
    assert(orig_lt == res_lt);
    assert(orig_ge == res_ge);

    // Multiconjunto y longitud preservados
    auto A = original, B = res;
    sort(A.begin(), A.end()); sort(B.begin(), B.end());
    assert(A == B);
    assert(original.size() == res.size());
}

void expect_exact(ListNode* head, const vector<int>& expected) {
    assert(listToVec(head) == expected);
}

void run_test(int id, const vector<int>& input, int x, const vector<int>& expected) {
    ListNode* head = buildList(input);
    Solution sol;
    ListNode* out = sol.solucion(head, x);
    cout << "Test " << id << " ... ";
    validate_partition(input, x, out);
    expect_exact(out, expected);
    cout << "OK\n";
    freeList(out);
}
/* -------- 10 tests -------- */
int main() {
    // 1) Caso clásico
    run_test(1, {1,4,3,2,5,2}, 3, {1,2,2,4,3,5});

    // 2) Lista vacía
    run_test(2, {}, 1, {});

    // 3) Un nodo < x
    run_test(3, {1}, 2, {1});

    // 4) Un nodo >= x
    run_test(4, {2}, 2, {2});

    // 5) Duplicados alrededor del pivote
    run_test(5, {3,3,2,2,3}, 3, {2,2,3,3,3});

    // 6) Alternando valores
    run_test(6, {5,1,6,2,7,3}, 4, {1,2,3,5,6,7});

    // 7) Mezcla con negativos y 0 como pivote
    run_test(7, {0,-1,2}, 0, {-1,0,2});

    // 8) Cambio de cabeza
    run_test(8, {4,1}, 3, {1,4});

    // 9) Descendente largo
    run_test(9, {9,8,7,6,5,4,3,2,1,0}, 5, {4,3,2,1,0,9,8,7,6,5});

    // 10) Extremos de int
    run_test(10, {100000000, -100000, 0}, 1, {-100000,0,100000000});

    cout << "Todos los tests pasaron. \n";
    return 0;
}