
import java.util.ArrayDeque;

/**
 * Copyright 2021 WeGene.Inc
 * Created by West 0n 2021/6/2
 */

public class RedBlackTree<V extends Comparable<V>> {

    private static class Node<V extends Comparable<V>> {
        Node(V value) {
            this.value = value;
            red = true;
        }
        V value;
        Node<V> parent;
        Node<V> left, right;
        Boolean red;
    }

    private Node <V> root;
    private int size;

    public Boolean addValues(V value) {
        if (value == null) return false;

        Node<V> current = root;
        Node<V> p = current;
        while (current != null) {
            p = current;
            if (current.value.compareTo(value)> 0) {
                current = current.left;
            } else if (current.value.compareTo(value) < 0) {
                current = current.right;
            } else {
                return false;
            }
        }
        Node<V> newNode = new Node<>(value);
        newNode.parent = p;
        if (root ==  null) {
            root = newNode;
            root.red = false;
            size = 1;
            return true;
        }
        if (p.value.compareTo(value) > 0) p.left = newNode;
		else p.right = newNode;

        balanceAfterInsertion(newNode);
        size = size + 1;
        return true;
    }

    private void balanceAfterInsertion(Node<V> node) {
        Node<V> parent , grandP;
        while (true) {
            if ((parent = node.parent) == null) {
                node.red = false;
                root = node;
                return;
            }
            if ((grandP = parent.parent) == null || !parent.red ) {
                return;
            }
            if (parent == grandP.left) {
                Node<V> uncle = grandP.right;
                if (isRed(uncle)) {
                    uncle.red = false;
                    parent.red = false;
                    grandP.red = true;
                    node = grandP;
                } else {
                    if (node == parent.right) {
                        node = parent;
                        rotateLeft(parent);
                        parent = node.parent;
                        grandP = parent == null ? null : parent.parent;
                    }
                    if (parent != null) {
                        parent.red = false;
                        if (grandP != null) {
                            grandP.red = true;
                            rotateRight(grandP);
                        }
                    }
                }
            } else {
                Node<V> uncle = grandP.left;
                if (isRed(uncle)) {
                    uncle.red = false;
                    parent.red = false;
                    grandP.red = true;
                    node = grandP;
                } else {
                    if (node == parent.left) {
                        node = parent;
                        rotateRight(parent);
                        parent = node.parent;
                        grandP = parent == null ? null : parent.parent;
                    }
                    if (parent != null) {
                        parent.red = false;
                        if (grandP != null) {
                            grandP.red = true;
                            rotateLeft(grandP);
                        }
                    }
                }
            }
        }
    }

    public Boolean containValue(V value) {
        if (value == null) return false;
        return getNode(value) != null;
    }

    public Boolean removeValue(V value) {
        if (value == null) return true;
        Node<V> current = getNode(value);
        if (current == null) return false;

        Node<V> replaceNode = null;
        if (current.left != null && current.right != null) {
            Node<V> min = min(current.right);
            current.value = min.value;
            current = min;
            if (min.right != null) replaceNode = min.right;
        } else if (current.left != null) {
            replaceNode = current.left;
        } else if (current.right != null) {
            replaceNode = current.right;
        }

        if (replaceNode != null) {
            Node<V> parent = current.parent;
            replaceNode.parent = parent;
            if (parent.left == current) parent.left = replaceNode;
            else if (parent.right == current) parent.right = replaceNode;
            current.left = current.right = current.parent = null;
            balanceAfterDeletion(replaceNode);
        } else {
            balanceAfterDeletion(current);
            if (current.parent != null) {
                if (current.parent.left == current) current.parent.left = null;
                else if (current.parent.right == current) current.parent.right = null;
            } else {
                root = null;
            }
            current.parent = null;
        }
        size--;
        return true;
    }

    private void balanceAfterDeletion(Node<V> node) {
        while (node != root && !node.red) {
            Node<V> parent = node.parent;
            if (parent.left == node) {
                Node<V> bRight = parent.right;
                if (!parent.red && isRed(bRight)) {
                    parent.red = true;
                    bRight.red = false;
                    rotateLeft(parent);
                    bRight = parent.right;
                }
                if (!isRed(bRight.left) && !isRed(bRight.right)) {
                    bRight.red = true;
                    node = parent;
                } else {
                    if (!isRed(bRight.right)) {
                        bRight.red = true;
                        bRight.left.red = false;
                        rotateRight(bRight);
                        bRight = parent.right;
                    }
                    bRight.red = parent.red;
                    parent.red = false;
                    bRight.right.red = false;
                    rotateLeft(parent);
                    node = root;
                }
            } else {
                Node<V> bLeft = parent.left;
                if (!parent.red && isRed(bLeft)) {
                    parent.red = true;
                    bLeft.red = false;
                    rotateRight(parent);
                    bLeft = parent.left;
                }
                if (!isRed(bLeft.right) && !isRed(bLeft)) {
                    bLeft.red = true;
                    node = parent;
                } else {
                    if (!isRed(bLeft.left)) {
                        bLeft.red = true;
                        bLeft.right.red = false;
                        rotateLeft(bLeft);
                        bLeft = parent.left;
                    }
                    bLeft.red = parent.red;
                    parent.red = false;
                    bLeft.left.red = false;
                    rotateRight(parent);
                    node = root;
                }
            }
        }
        node.red = false;
    }

    public int getSize() {
        return size;
    }

    public void clear() {
        root = null;
        size = 0;
    }

    private Node<V> min(Node<V> node) {
        Node<V> p = node;
        while(p.left != null) p = p.left;
        return p;
    }

    private Node<V> getNode(V value) {
        Node<V> current = root;
        while (current != null) {
            if (current.value.compareTo(value) > 0) {
                current = current.left;
            } else if (current.value.compareTo(value) < 0) {
                current = current.right;
            } else {
                return current;
            }
        }
        return null;
    }

    private void rotateLeft(Node<V> node) {
        if (node == null || node.right == null) return;
        Node<V> parent = node.parent;
        Node<V> p = node.right;
        node.parent = p;
        node.right = p.left;
        if (p.left != null) p.left.parent = node;
        p.left = node;
        p.parent = parent;
        if (parent == null) root = p;
        else {
            if (parent.left == node) parent.left = p;
            else parent.right = p;
        }
    }

    private void rotateRight(Node<V> node) {
        if (node == null || node.left == null) return;
        Node<V> parent = node.parent;
        Node<V> p = node.left;
        node.parent = p;
        node.left = p.right;
        if (p.right != null) p.right.parent = node;
        p.right = node;
        p.parent = parent;
        if (parent == null) {
            root = p;
        } else {
            if (parent.left == node) parent.left = p;
            else parent.right = p;
        }
    }

    private Boolean isRed(Node<V> node) {
        return node != null && node.red;
    }

    public void printTree() {
        if (root == null) {
            System.out.println("null Tree");
            return;
        }
        Node<V> divider = new Node<V>(null);
        ArrayDeque<Node<V>> queue = new ArrayDeque<>(size+1);
        queue.offer(root);
        queue.offer(divider);
        int level = 0;
        while (!queue.isEmpty()) {
            Node<V> node = queue.poll();
            if (node == null) break;
            if (node.value == null) {//divider
                if (queue.isEmpty()) break;
                else queue.offer(node);
                System.out.println("level " + level);
                level++;
            } else {
                System.out.print(node.value.toString()+"(" + node.red + ") ");
                if (node.left != null) queue.offer(node.left);
                if (node.right != null) queue.offer(node.right);
            }
        }
        System.out.print("level " + level + "\n");
    }

    public void printOrder() {
        if (root == null) {
            return;
        }
        printOrder_(root);
        System.out.println();
    }

    private void printOrder_(Node<V> node) {
        if (node == null) return;
        if (node.left != null) printOrder_(node.left);
        System.out.print(node.value.toString() + " ");
        printOrder_(node.right);
    }
}