import { countRouts } from "./all-routes.mjs";

let idx = 0;
function assertRoute(locations, start, finish, fuel, expected) {
  const result = countRouts(locations, start, finish, fuel);
  if (result == expected) {
    console.log(`case ${idx} success`);
  } else {
    console.log(`case ${idx} failed: wanted ${expected} but was ${result}`);
  }
  idx++;
}

assertRoute([1, 2], 0, 1, 1, 1);
assertRoute([1, 2, 3], 0, 2, 2, 2);
assertRoute([2, 3, 6, 8, 4], 1, 3, 5, 4);
assertRoute([4, 3, 1], 1, 0, 6, 5);
assertRoute([1,2,3], 0, 2, 40, 615088286);
