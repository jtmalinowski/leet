
export function countRouts(locations, start, finish, fuel) {
  const pack = [];

  let fuelUse = 0;
  pack[fuelUse] = [];
  pack[fuelUse][start] = 1;

  while (true) {
    fuelUse++;
    if (fuelUse > fuel) { break; }

    pack[fuelUse] = [];

    for (let idx = 0; idx < locations.length; idx++) {
      let ways = 0;
      for (let idxFrom = 0; idxFrom < locations.length; idxFrom++) {
        if (idxFrom == idx) { continue; }
        const diff = Math.abs(locations[idx] - locations[idxFrom]);

        if (diff == 0) {
          throw new Error('Infinite Loop.');
        }

        const fuelPrev = fuelUse - diff;
        if (fuelPrev < 0) { continue; }
        if (!pack[fuelPrev][idxFrom]) { continue; }
        
        ways += pack[fuelPrev][idxFrom];
        ways = ways % (10e8 + 7);
      }

      pack[fuelUse][idx] = ways;
    }
  }

  let waysAnyFuel = 0;
  for (let idx = 0; idx <= fuel; idx++) {
    if (!pack[idx][finish]) { continue; }
    waysAnyFuel += pack[idx][finish];
    waysAnyFuel = waysAnyFuel % (10e8 + 7);
  }

  return waysAnyFuel;
}
