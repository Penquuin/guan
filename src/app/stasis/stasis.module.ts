import { NgModule } from "@angular/core";
import { CommonModule } from "@angular/common";
import { BasepageComponent } from "./basepage/basepage.component";
import { MdLoverComponent } from "./md-lover/md-lover.component";
import { MarkdownModule } from "ngx-markdown";

@NgModule({
  declarations: [BasepageComponent, MdLoverComponent],
  imports: [CommonModule, MarkdownModule.forChild()],
  exports: [BasepageComponent, MdLoverComponent],
})
export class StasisModule {}
