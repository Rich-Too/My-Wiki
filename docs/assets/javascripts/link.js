(function () {
    var beian = document.querySelector("body > div.md-container > footer > div > div > div")
    var divElement = document.createElement("div");
    var linkElement = document.createElement("a");
    linkElement.href = "https://beian.miit.gov.cn/";
    linkElement.textContent = "浙ICP备2022021436号-1";
    divElement.appendChild(linkElement);

    beian.insertBefore(divElement, beian.firstChild);
})();