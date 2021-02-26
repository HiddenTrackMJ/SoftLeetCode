package hidden.track;

/**
 * Author: Jason
 * Date: 2020/9/24
 * Time: 15:49
 */
public class leet_1 {

  public static int jumpFloor(int target) {
    if (target <= 2) return  target;
    int x = 1, y  = 2, tmp;
    for (int i = 3; i <= target; i++) {
      tmp = y;
      y = x + y;
      x = tmp;
//      System.out.println("i: " + i + ", x: " + x + ", y: " + y + ", tmp: " + tmp);
    }
    return y;
  }

  private static int q_select(int[] a, int left, int right, int k) {
//    if (left < right) return;
    int i = left, j = right;
    int pivot = a[left];
    while(i < j) {
      while (i < j && a[j] >= pivot) j--;
      a[i] = a[j];
      while (i < j && a[i] <= pivot) i++;
      a[j] = a[i];
    }
    a[i] = pivot;
    if (i + 1 > k) return q_select(a, left, i - 1, k);
    else if (i + 1 < k) return q_select(a, i + 1, right, k);
    else return a[i];
  }

  public static int findKth(int[] a, int n, int K) {
    // write code here
//    int len = a.length;
    return q_select(a, 0, n - 1, K);
  }



  public static void main(String[] args) {
    System.out.println("hello");
    int rst = jumpFloor(5);
//    System.out.println("rst: " + rst);
    int[] a = {1,3,5,6,2,2};
    int rst2 = findKth(a,6,2);
    System.out.println("rst2: " + rst2);
  }
}
