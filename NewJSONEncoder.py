fileName = "text"; keys = []; keyFound = 0; result = [];
with open(fileName) as f:
    for line in f:
        if line.strip() != "":
            if keyFound:
                vals = line.split(',');
                singleUser = {};
                valIndex = 0;
                keyIndex = 0;
                while valIndex < len(vals) and keyIndex < len(keys):
                    singleUser[keys[keyIndex]] = vals[valIndex].strip();
                    keyIndex  = keyIndex + 1;
                    valIndex = valIndex + 1;
                
                while keyIndex < len(keys):
                    singleUser[keys[keyIndex]] = "";
                    keyIndex  = keyIndex + 1;
                result.append(singleUser);
            else:
                keys = line.split(',');
                keyIndex = 0;
                while keyIndex < len(keys):
                    keys[keyIndex] = keys[keyIndex].strip();
                    keyIndex = keyIndex + 1;
                keyFound = 1;
print (result);
