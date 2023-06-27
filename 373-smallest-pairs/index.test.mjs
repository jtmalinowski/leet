import { kSmallestPairs } from "./index.mjs";

let idx = 0;
function assertRound(expected, nums1, nums2, k) {
  const result = kSmallestPairs(nums1, nums2, k);
  if (JSON.stringify(result) == JSON.stringify(expected)) {
    console.log(`case ${idx} success`);
  } else {
    console.log(`case ${idx} failed: wanted ${JSON.stringify(expected)} but was ${JSON.stringify(result)}`);
  }
  idx++;
}

assertRound([[1,2],[1,4],[1,6]], [1,7,11], [2,4,6], 3);
assertRound([[1,1],[1,1]], [1,1,2], [1,2,3], 2);
assertRound([[1,3],[2,3]], [1,2], [3], 3);
assertRound([[1,-1],[2,-1],[1,1],[1,2],[2,1],[4,-1],[2,2],[4,1],[4,2]], [1,2,4], [-1,1,2], 100);
assertRound([[1,1],[1,1],[1,2],[1,2],[2,1],[2,2],[1,3],[1,3],[2,3]], [1,1,2], [1,2,3], 10);
