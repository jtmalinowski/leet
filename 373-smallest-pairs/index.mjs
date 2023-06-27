/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @param {number} k
 * @return {number[][]}
 */
export function kSmallestPairs(nums1, nums2, k) {
  const res = [];

  let GUARD = null;
  GUARD = { next: GUARD };
 
  let pairsHead = {
    l: 0,
    r: 0,
    pair: [nums1[0], nums2[0]],
    sum: nums1[0] + nums2[0],
    next: GUARD,
  };

  // do not recalculate pairs, keep them in a sorted linked list
  // we always take the head, because it's smallest
  // heap would be better (logn) but javascript
  // linked list has delete O(1) and insert O(n)
  // seems good enough, savings come from not recreating objects mostly

  // for each left keep an index of the right, start with 0
  // when a l-r pair is taken, increase r for the l
  // repeat

  let node = pairsHead;
  for (let l = 1; ; l++) {
    if (l >= nums1.length) { break; }
    node.next = {
      l, r: 0, pair: [nums1[l], nums2[0]], sum: nums1[l] + nums2[0], next: GUARD,
    };
    node = node.next;
  }

  while (res.length < k) {
    res.push(pairsHead.pair);
    const nextL = pairsHead.l;
    const nextR = pairsHead.r + 1;
    pairsHead = pairsHead.next;

    if (nextR < nums2.length) {
      const newNode = {
        l: nextL,
        r: nextR,
        pair: [nums1[nextL], nums2[nextR]],
        sum: nums1[nextL] + nums2[nextR],
        next: GUARD,
      };

      if (pairsHead == GUARD) {
        pairsHead = newNode;
      } else if (pairsHead.sum >= newNode.sum) {
        newNode.next = pairsHead;
        pairsHead = newNode;
      } else {
        let insertionNode = pairsHead;
        while (insertionNode.next != GUARD && insertionNode.next.sum < newNode.sum) { insertionNode = insertionNode.next; }
        newNode.next = insertionNode.next;
        insertionNode.next = newNode;
      }
    }

    if (pairsHead == GUARD) { break; }
  }

  return res;
};
