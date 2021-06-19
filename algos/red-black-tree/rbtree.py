
class Node:
    def __init__(self, val=None, is_black):
        self.left = None
        self.right = None
        self.val = val
        self.is_black = is_black

def right_rotate(node):
