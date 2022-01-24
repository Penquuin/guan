import { Component, OnInit } from "@angular/core";
import { FormControl, FormGroup, Validators } from "@angular/forms";

type leddit = {
  data: Array<{
    selftext: string;
    title: string;
    author: string;
    author_fullname: string;
    url: string;
    author_flair_text: string;
    author_flair_background_color: string;
    link_flair_text: string;
    link_flair_background_color: string;
  }>;
};
@Component({
  selector: "app-redie",
  templateUrl: "./redie.component.html",
  styleUrls: ["./redie.component.scss"],
})
export class RedieComponent implements OnInit {
  redieForm = new FormGroup({
    name: new FormControl(undefined, [Validators.required, Validators.minLength(3)]),
  });

  result: leddit | undefined;
  searching = false;
  constructor() {}

  get name() {
    return this.redieForm.get("name");
  }

  onSubmit() {
    this.searching = true;
    fetch(
      `https://api.pushshift.io/reddit/search/submission/?subreddit=${this.redieForm.value.name}&sort=desc&sort_type=created_utc&size=20`,
    )
      .then((res) => {
        return res.text();
      })
      .then((str) => {
        this.searching = false;
        this.result = JSON.parse(str) as leddit;
      });
  }

  ngOnInit(): void {}
}
