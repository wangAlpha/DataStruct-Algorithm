package main

import (
	"fmt"
)

type ListNode struct {
	data int
	succ *ListNode
}

func (list *ListNode) printListFromTailToHead() {
	if list == nil {
		return
	}
	var new_head *ListNode
	for list != nil {
		node := list
		list = list.succ
		new_head = insert(new_head, node)
	}
	for new_head != nil {
		fmt.Printf("%d ", new_head.data)
		new_head = new_head.succ
	}
}

func insert(head *ListNode, node *ListNode) *ListNode {
	node.succ = head
	return node
}

func main() {
	var head *ListNode
	for i := 0; i < 5; i++ {
		node := new(ListNode)
		node.data = i
		head = insert(head, node)
	}
	node := head
	for node != nil {
		fmt.Printf("%d ", node.data)
		node = node.succ
	}
	println()
	head.printListFromTailToHead()
	println()
}
