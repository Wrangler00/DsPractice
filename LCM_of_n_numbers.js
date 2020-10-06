//to find LCM of n numbers in array

//Also tutorial : https://www.geeksforgeeks.org/lcm-of-given-array-elements/
//Also refer: https://www.freecodecamp.org/learn/javascript-algorithms-and-data-structures/intermediate-algorithm-scripting/smallest-common-multiple

//JS solution

function gcd(a,b){
  if(b==0)
    return a;
  return gcd(b,a%b);
}

function smallestCommons(arr) {
  arr.sort((a,b)=>a-b);
  let ans = arr[0];
  
  for(let i=arr[0]+1;i<=arr[1];i++)
    ans = (ans*i)/gcd(ans,i);

  return ans;
}

console.log(smallestCommons([1,13]));
