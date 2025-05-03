/**
 * @param {Function} fn
 * @return {Object}
 */
Array.prototype.groupBy = function(fn) {
    return this.reduce((groupItem, item)=>{
        const key = fn(item);
        groupItem[key]||=[]
        groupItem[key].push(item);
        return groupItem;
    }, {})
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */