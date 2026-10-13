int trap(int* height, int heightSize) {    
  int left = 0;
  int right = heightSize - 1;
  int leftMax = 0;
  int rightMAx = 0;
  int water  = 0;

  while (left < right) {
    if (height[left] < height[right]) {
      if (height[left] >= leftMax) 
        leftMax = height[left];
      else 
        water += leftMax - height[left];
      left++;
    }else {
      if (height[right] >= rightMAx) 
        rightMAx = height[right];
      else 
        water += rightMAx - height[right];
      right--;
    }
  }

  return water;
}