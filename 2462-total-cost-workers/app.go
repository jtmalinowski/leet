package main

import (
  "container/heap"
  "fmt"
)

// An Item is something we manage in a cost queue.
type Item struct {
	cost int
  originalIndex int
	_index int
}

type PriorityQueue []*Item

func (pq PriorityQueue) Len() int { return len(pq) }

func (pq PriorityQueue) Less(i, j int) bool {
  if (pq[i].cost == pq[j].cost) {
    return pq[i].originalIndex < pq[j].originalIndex  
  }
	return pq[i].cost < pq[j].cost
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
	pq[i]._index = i
	pq[j]._index = j
}

func (pq *PriorityQueue) Push(x any) {
	n := len(*pq)
	item := x.(*Item)
	item._index = n
	*pq = append(*pq, item)
}

func (pq *PriorityQueue) Pop() any {
	old := *pq
	n := len(old)
	item := old[n-1]
	old[n-1] = nil  // avoid memory leak
	item._index = -1 // for safety
	*pq = old[0 : n-1]
	return item
}

func totalCost(costs []int, k int, candidates int) int64 {
  pq := make(PriorityQueue, 0)
  heap.Init(&pq)

  nextUp := 0
  for ; ; nextUp++ {
    if nextUp >= candidates { break }
    if nextUp >= len(costs) { break }

    heap.Push(&pq, &Item{
      cost: costs[nextUp],
      originalIndex: nextUp,
    })
  }

  nextDown := len(costs) - 1
  for {
    if (nextDown <= len(costs) - candidates - 1) { break }
    if (nextDown <= nextUp) { break }

    heap.Push(&pq, &Item{
      cost: costs[nextDown],
      originalIndex: nextDown,
    })
    nextDown--
  }

  sum := int64(0)
  taken := 0

  for {
    nextItem := heap.Pop(&pq).(*Item)

    sum += int64(nextItem.cost)
    taken++

    if (len(pq) == 0 || taken == k) { break }

    if (nextUp > nextDown) { continue }
    if (nextItem.originalIndex < nextUp) {
      heap.Push(&pq, &Item{
        cost: costs[nextUp],
        originalIndex: nextUp,
      })
      nextUp++
    } else {
      heap.Push(&pq, &Item{
        cost: costs[nextDown],
        originalIndex: nextDown,
      })
      nextDown--
    }
  }

  return sum
}

func main() {
  fmt.Println(totalCost([]int{17,12,10,2,7,2,11,20,8}, 3, 4))
  fmt.Println(totalCost([]int{1,2,4,1}, 3, 3))
  fmt.Println(totalCost([]int{1,2,3,4}, 5, 5))
  fmt.Println(totalCost([]int{1,2,3,4}, 1, 2))
  fmt.Println(totalCost([]int{2,2,2,2,2,2,1,4,5,5,5,5,5,2,2,2,2,2,2,2,2,2,2,2,2,2},7,3))
}
