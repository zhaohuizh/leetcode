int addDigits(int num) {
  if (num == 0) return 0;
  int ret = num % 9;
  return ret == 0 ? 9 : ret;
}
