import { Component, Input, OnInit } from "@angular/core";

@Component({
  selector: "app-md-lover",
  templateUrl: "./md-lover.component.html",
  styleUrls: ["./md-lover.component.scss"],
})
export class MdLoverComponent implements OnInit {
  constructor() {}
  @Input() src!: string;

  onLoad() {
    this.loaded = true;
  }

  loaded = false;

  ngOnInit(): void {}
}
