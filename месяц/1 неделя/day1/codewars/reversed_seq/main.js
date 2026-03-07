const reverseSeq = (n) => {
  let resArr = [];
  for (i = 1; i <= n; i++) {
    resArr.push(i);
  }

  return resArr.reverse();
};

console.log(reverseSeq(5));
