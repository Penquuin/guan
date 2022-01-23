import { NgModule } from "@angular/core";
import { CommonModule } from "@angular/common";
import { HomeComponent } from "./home/home.component";
import { NotfoundComponent } from "./notfound/notfound.component";
import { MarkdownModule } from "ngx-markdown";
import { GradesComponent } from "./grades/grades.component";
import { FormsModule, ReactiveFormsModule } from "@angular/forms";

@NgModule({
  declarations: [HomeComponent, NotfoundComponent, GradesComponent],
  imports: [CommonModule, MarkdownModule.forChild(), ReactiveFormsModule, FormsModule],
  exports: [HomeComponent],
})
export class DynaModule {}
