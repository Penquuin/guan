import { Component, OnInit } from "@angular/core";
import { FormBuilder, Validators } from "@angular/forms";

type info = { year: string; grade: string; semester: string; exam: string };
const big5s = [
  "%B4%C1%AA%EC%BD%C6%B2%DF%A6%D2",
  "%B2%C4%A4%40%A6%B8%B4%C1%A4%A4%A6%D2",
  "%B2%C4%A4G%A6%B8%B4%C1%A4%A4%A6%D2",
  "%B4%C1%A5%BD%A6%D2",
];

@Component({
  selector: "app-grades",
  templateUrl: "./grades.component.html",
  styleUrls: ["./grades.component.scss"],
})
export class GradesComponent implements OnInit {
  constructor(private fb: FormBuilder) {}
  public ROCYear = new Date().getFullYear() - 1911;

  public infoform = this.fb.group({
    year: this.fb.control("", [Validators.required, Validators.minLength(3), Validators.pattern("^[0-9]*$")]),
    grade: this.fb.control("", Validators.required),
    semester: this.fb.control("", Validators.required),
    exam: this.fb.control("", Validators.required),
  });
  ngOnInit(): void {}
  changeGrade(e: any) {
    console.log(e.target.value);
    this.grade!.setValue(e.target.value, {
      onlySelf: true,
    });
  }
  changeSemester(e: any) {
    this.semester!.setValue(e.target.value, {
      onlySelf: true,
    });
  }
  changeExam(e: any) {
    this.exam!.setValue(e.target.value, {
      onlySelf: true,
    });
  }
  get year() {
    return this.infoform.get("year");
  }
  get grade() {
    return this.infoform.get("grade");
  }
  get semester() {
    return this.infoform.get("semester");
  }
  get exam() {
    return this.infoform.get("exam");
  }

  onSubmit(): void {
    const no = this.infoform.value as info;
    const data = { ...no };
    if (data.semester === "2") data.exam = ((parseInt(data.exam) as number) - 1).toString();
    const to = `http://shinher.hlhs.hlc.edu.tw/online/selection_student/student_subjects_number.asp?action=%A6U%A6%A1%A6%A8%C1Z&thisyear=${
      data.year
    }&thisterm=1&number=${parseInt(data.grade) + 9}${data.semester}${data.exam}&exam%5Fname=${
      big5s[parseInt(no.exam) - 1]
    }`;
    window.open(to, "_blank");
  }

  href =
    "http://shinher.hlhs.hlc.edu.tw/online/selection_student/student_subjects_number.asp?action={}&thisyear={}&thisterm=1&number=1013&exam%5Fname=%B2%C4%A4G%A6%B8%B4%C1%A4%A4%A6%D2";
}
