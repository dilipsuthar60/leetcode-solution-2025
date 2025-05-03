interface Array<T> {
    groupBy(fn: (item: T) => string): Record<string, T[]>
}


Array.prototype.groupBy = function(fn) {
    let groupByObject={};
    for(let item of this){
        let key = fn(item);
        groupByObject[key]||=[]
        groupByObject[key].push(item);
    }
    return groupByObject;
}

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */