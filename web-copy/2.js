/**
 * 禁用断点+切换设备仿真
 * 可以不跳转
 */
/**
 * Query:
 * 您好，请问怎么访问html中一个元素的::before伪元素
 */

/**
 * @name {node}
 * @type {HTMLSpanElement}
 */
for (const node of temp1.childNodes) {
  noiseInput.value += getComputedStyle(node, "::before")
    .getPropertyValue("content")
    .replace(/"/g, "");
  noiseInput.value += getComputedStyle(node, "::after")
    .getPropertyValue("content")
    .replace(/"/g, "");
}
