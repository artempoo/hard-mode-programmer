function positiveSum(arr) {
  let acc = 0;
  for (i = 0; i < arr.length; i++) {
    if (arr[i] > 0) acc += arr[i];
  }

  return acc;
}
