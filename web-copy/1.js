/**
 * @type {HTMLInputElement}
 */
const noiseInput = document.getElementById("noiseInput");
for (const line of document.getElementsByClassName("noiseLine"))
  noiseInput.value += line.textContent;
