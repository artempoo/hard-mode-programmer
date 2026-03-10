class FArray {
  value;
  constructor(value) {
    this.value = value;
  }

  filter(callback) {
    const array = this.value;
    if (typeof callback != "function") {
      return new TypeError("Мать твою а ну иди сюда ты говно собачее");
    }

    const resArr = [];

    for (let i = 0; i < array.length; i++) {
      const res = callback(array[i], i, array);
      if (res) {
        resArr.push(array[i]);
      }
    }

    return resArr;
  }
}

const arr = new FArray([0, 1, 2, 3, 4, 5]);

const res = arr.filter((item) => item >= 3);
