var thumbnail = document.querySelector('#thumbnail');

window.addEventListener("message", function(e) {
    console.log('iframe.js received message', e.data);
    thumbnail.src = e.data.img;
    thumbnail.style.display = 'initial';
});

window.parent.postMessage({
    type: "request",
    data: "Hello from child"
}, '*');

console.log('iframe.js loaded');
