function stringToBinary(str){
    let binary = '';
    for(let i=0; i<str.length; i++){
        // Convert each character to its binary representation
        binary += str[i].charCodeAt(0).toString(2).padStart(8, '0');
    }
    return binary;
}


function binaryToString(binary){
    let str = '';
    for(let i=0; i<binary.length; i+=8){
         // Convert each 8 bits to its character equivalent
        str+=String.fromCharCode(parseInt(binary.substr(i, 8), 2));
    }
    return str;
}

// const inputString = "Ranjan Kumar Pandit.";
// const binaryString = stringToBinary(inputString);
// console.log("String to Binary: ", binaryString);

// const originalString = binaryToString(binaryString);
// console.log("Binary to String: ", originalString);

const binaryString =  "0101001001100001011011100110101001100001011011100010000001001011011101010110110101100001011100100010000001010000011000010110111001100100011010010111010000101110"
const outputString = binaryToString( binaryString);
console.log("Binary to String: ",outputString );